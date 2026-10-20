/*!
 * author: manhhomienbienthuy
 * created: 2026-10-20T00:33:21+00:00
 * https://codeforces.com/gym/106759/problem/H
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

    vector<string> g(n);
    for (auto& s : g) cin >> s;

    auto check = [&](int m) {
      vector dp(n, vector<int>(n, INT_MAX));
      dp[0][0] = 1;

      for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
          if (!row && !col) continue;

          if (row && dp[row - 1][col] <= m) {
            int cand =
                (g[row - 1][col] == g[row][col]) ? dp[row - 1][col] + 1 : 1;

            dp[row][col] = min(dp[row][col], cand);
          }

          if (col && dp[row][col - 1] <= m) {
            int cand =
                (g[row][col - 1] == g[row][col]) ? dp[row][col - 1] + 1 : 1;

            dp[row][col] = min(dp[row][col], cand);
          }
        }
      }

      return (dp[n - 1][n - 1] <= m);
    };

    int lo = 1, hi = 2 * n - 1;

    while (lo <= hi) {
      int mid = (lo + hi) >> 1;

      if (check(mid))
        hi = mid - 1;
      else
        lo = mid + 1;
    }

    cout << lo << '\n';
  }

  return 0;
}
