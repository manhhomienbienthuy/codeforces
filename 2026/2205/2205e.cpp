/*!
 * author: manhhomienbienthuy
 * created: 2026-07-06T02:28:48+00:00
 * https://codeforces.com/contest/2205/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> T(n);
    for (auto& x : T) cin >> x;

    vector<vector<int>> border(n, vector<int>(n, 0));

    for (int l = 0; l < n; l++) {
      int j = 0;

      for (int r = l + 1; r < n; r++) {
        while (j && T[r] != T[l + j]) {
          j = border[l][l + j - 1];
        }

        if (T[r] == T[l + j]) {
          j++;
        }

        border[l][r] = j;
      }
    }

    vector<int64_t> dp(n + 1, 0);
    dp[0] = 1;

    for (int r = 0; r < n; r++) {
      for (int l = 0; l <= r; l++) {
        if (!border[l][r]) dp[r + 1] = (dp[r + 1] + dp[l]) % MOD;
      }
    }

    cout << dp[n] << '\n';
  }

  return 0;
}
