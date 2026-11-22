/*!
 * author: manhhomienbienthuy
 * created: 2026-11-21T14:35:55+00:00
 * https://codeforces.com/contest/2287/problem/A1
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int x, y, m;
    string s;

    cin >> x >> y >> m >> s;

    int lim = x + y + m;
    vector<vector<bool>> dp(lim + 1, vector<bool>(lim + 1));

    dp[x][y] = true;

    int ans = x + y;

    for (char c : s) {
      vector<vector<bool>> ndp(lim + 1, vector<bool>(lim + 1));

      for (int a = 0; a <= lim; a++) {
        for (int b = 0; b <= lim; b++) {
          if (!dp[a][b]) continue;

          if (c == '+') {
            if (a > 0) ndp[a - 1][b + 1] = true;
            if (b > 0) ndp[a][b + 1] = true;
          } else {
            if (a > 0) ndp[a - 1][b] = true;
            if (b > 0) ndp[a + 1][b - 1] = true;
          }
        }
      }

      dp.swap(ndp);
      for (int a = 0; a <= lim; a++) {
        for (int b = 0; b <= lim; b++) {
          if (dp[a][b]) ans = max(ans, a + b);
        }
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
