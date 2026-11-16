/*!
 * author: manhhomienbienthuy
 * created: 2026-11-15T15:37:10+00:00
 * https://codeforces.com/contest/2285/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    int ans = min(n, k + 1);

    if (ans == n) {
      cout << n << '\n';
      continue;
    }

    vector<unordered_map<int, int>> pos(n);

    for (int l = 0; l < n; l++) {
      for (int r = l + 1; r < n && r < l + k + 2; r++) {
        int d = a[r] - a[l];

        if (d % (r - l)) continue;

        d /= (r - l);

        if (pos[l].find(d) == pos[l].end()) {
          pos[l][d] = r;
        }
      }
    }

    for (int l = 0; l < n && ans < n; l++) {
      for (auto& [d, nxt] : pos[l]) {
        if (nxt == -1) continue;

        int u = l;
        vector<int> b;

        b.push_back(u);

        while (true) {
          auto it = pos[u].find(d);

          if (it == pos[u].end() || it->second == -1) break;

          int v = it->second;
          it->second = -1;

          u = v;
          b.push_back(u);
        }

        int len = (int)b.size();

        for (int i = 0, r = 0; i < len; i++) {
          if (r < i) r = i;

          while (r < len) {
            int need = b[r] - b[i] + 1 - (r - i + 1);
            if (need > k) break;
            r++;
          }

          ans = max(ans, min(n, r - i + k));

          if (ans == n) break;
        }

        if (ans == n) {
          break;
        }
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
