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

    vector<int> pref_a(n + 1, 0), pref_b(m + 1, 0);
    for (int i = 0; i < n; i++) pref_a[i + 1] = (pref_a[i] + a[i] - '0') % 10;
    for (int i = 0; i < m; i++) pref_b[i + 1] = (pref_b[i] + b[i] - '0') % 10;

    if (pref_a[n] != pref_b[m]) {
      cout << -1 << '\n';
      continue;
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (pref_a[i] == pref_b[j])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    cout << dp[n][m] << '\n';
  }

  return 0;
}
