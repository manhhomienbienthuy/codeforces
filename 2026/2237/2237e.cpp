/*!
 * author: manhhomienbienthuy
 * created: 2026-06-18T16:36:46+00:00
 * https://codeforces.com/contest/2237/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        vector<int> cyc(n + 1, -1), pos(n + 1, -1);
        vector<vector<int>> cycs;
        for (int i = 1; i <= n; i++) {
            if (cyc[i] != -1) continue;
            int ci = cycs.size();
            cycs.push_back({});
            int j = i;
            while (cyc[j] == -1) {
                cyc[j] = ci;
                pos[j] = cycs[ci].size();
                cycs[ci].push_back(j);
                j = a[j];
            }
        }

        int nc = cycs.size();
        vector<int> c_target(nc, -1), crot(nc, -1);
        vector<bool> used(nc, false);
        bool ok = true;

        for (int i = 1; i <= n && ok; i++) {
            if (b[i] == -1) continue;
            int ci = cyc[i], cj = cyc[b[i]];
            int L = cycs[ci].size(), Lj = cycs[cj].size();
            if (L != Lj) {
                ok = false;
                break;
            }
            int p = pos[i], q = pos[b[i]];
            int r = (q - p + L) % L;
            if (c_target[ci] == -1) {
                if (used[cj]) {
                    ok = false;
                    break;
                }
                c_target[ci] = cj;
                crot[ci] = r;
                used[cj] = true;
            } else {
                if (c_target[ci] != cj || crot[ci] != r) {
                    ok = false;
                    break;
                }
            }
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        for (int ci = 0; ci < nc; ci++) {
            if (c_target[ci] == -1) continue;
            int cj = c_target[ci], r = crot[ci];
            int L = cycs[ci].size();
            for (int k = 0; k < L; k++) b[cycs[ci][k]] = cycs[cj][(r + k) % L];
        }

        map<int, set<int>> target;
        for (int ci = 0; ci < nc; ci++) {
            if (used[ci]) continue;
            int L = cycs[ci].size();
            for (int v : cycs[ci]) target[L].insert(v);
        }

        for (int i = 1; i <= n && ok; i++) {
            if (b[i] != -1) continue;
            int ci = cyc[i];
            int L = cycs[ci].size();
            auto it = target.find(L);
            if (it == target.end() || it->second.empty()) {
                ok = false;
                break;
            }
            int v = *it->second.begin();
            int cj = cyc[v];
            int p = pos[i], q = pos[v];
            int r = (q - p + L) % L;
            used[cj] = true;
            for (int u : cycs[cj]) it->second.erase(u);
            for (int k = 0; k < L; k++) b[cycs[ci][k]] = cycs[cj][(r + k) % L];
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
    }
}
