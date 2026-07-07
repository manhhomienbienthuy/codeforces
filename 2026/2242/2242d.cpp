/*!
 * author: manhhomienbienthuy
 * created: 2026-07-06T15:20:13+00:00
 * https://codeforces.com/contest/2242/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    int n = (int)a.size(), m = (int)b.size();

    vector<int> pa(n + 1, 0), pb(m + 1, 0);
    for (int i = 0; i < n; i++) pa[i + 1] = (pa[i] + a[i] - '0') % 10;
    for (int i = 0; i < m; i++) pb[i + 1] = (pb[i] + b[i] - '0') % 10;

    vector<vector<int>> cmax(m + 1, vector<int>(10, -1));
    cmax[0][0] = 0;

    int ans = -1;
    for (int i = 1; i <= n; i++) {
      vector<int> rmax(10, -1);
      vector<tuple<int, int, int>> upd;

      for (int j = 1; j <= m; j++) {
        for (int g = 0; g < 10; g++) {
          if (cmax[j - 1][g] > rmax[g]) rmax[g] = cmax[j - 1][g];
        }

        int g = ((pa[i] - pb[j]) % 10 + 10) % 10;
        if (rmax[g] >= 0) {
          int val = rmax[g] + 1;
          upd.push_back({j, g, val});
          if (i == n && j == m) ans = max(ans, val);
        }
      }

      for (auto [j, g, val] : upd) {
        cmax[j][g] = max(cmax[j][g], val);
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
