#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<bitset<500>> R(n), C(n);
        char buf[501];
        for (int i = 0; i < n; i++) {
            scanf("%s", buf);
            for (int j = 0; j < n; j++) {
                if (buf[j] == '1') {
                    R[i].set(j);
                    C[j].set(i);
                }
            }
        }
        bool valid = true;
        // Check reflexivity: s[i][i] = 1
        for (int i = 0; i < n; i++) {
            if (!R[i].test(i)) { valid = false; break; }
        }
        // Check antisymmetry: not both s[i][j]=1 and s[j][i]=1 for i!=j
        if (valid) {
            for (int i = 0; i < n && valid; i++) {
                for (int j = i + 1; j < n && valid; j++) {
                    if (R[i].test(j) && R[j].test(i)) valid = false;
                }
            }
        }
        // Check transitivity: s[i][j]=1 => R[j] subset of R[i]
        if (valid) {
            for (int i = 0; i < n && valid; i++) {
                for (int j = 0; j < n && valid; j++) {
                    if (j != i && R[i].test(j)) {
                        if ((R[j] & ~R[i]).any()) valid = false;
                    }
                }
            }
        }
        vector<pair<int,int>> edges;
        if (valid) {
            // Extract Hasse diagram (covering relation)
            // Edge i->j is direct iff s[i][j]=1 and no intermediate k
            // R[i] & C[j] = {k : s[i][k]=1 and s[k][j]=1}
            // Should be exactly {i, j} for a direct edge
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j || !R[i].test(j)) continue;
                    bitset<500> common = R[i] & C[j];
                    common.reset(i);
                    common.reset(j);
                    if (common.none()) {
                        edges.push_back({i, j});
                    }
                }
            }
            if ((int)edges.size() != n - 1) valid = false;
            // Check connectivity (undirected) - needed because
            // a DAG with n-1 edges is NOT necessarily a tree
            if (valid) {
                vector<vector<int>> adj(n);
                for (auto& [u, v] : edges) {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
                vector<bool> vis(n, false);
                queue<int> q;
                q.push(0);
                vis[0] = true;
                int cnt = 1;
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (int v : adj[u]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            cnt++;
                            q.push(v);
                        }
                    }
                }
                if (cnt != n) valid = false;
            }
        }
        if (!valid) {
            puts("No");
        } else {
            puts("Yes");
            for (auto& [u, v] : edges) {
                printf("%d %d\n", u + 1, v + 1);
            }
        }
    }
    return 0;
}
