/*!
 * author: manhhomienbienthuy
 * created: 2026-11-01T03:10:36+00:00
 * https://codeforces.com/contest/2278/problem/F
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
    int n, m;
    cin >> n >> m;

    int mx = m + 2;

    vector<vector<int>> dp1(n + 1, vector<int>(mx + 1)),
        dp2(n + 1, vector<int>(mx + 1));

    dp1[0][1] = 1;
    dp2[0][2] = 1;

    int ans = 0;

    for (int l = 1; l <= n; l++) {
      if (l < n) ans = (ans + dp2[l - 1][m + 2]) % MOD;

      if (l == n) {
        ans = (ans + dp1[l - 1][m + 1]) % MOD;
        ans = (ans + dp2[l - 1][m + 2]) % MOD;
        break;
      }

      vector<int> pref1(mx + 2), pref2(mx + 2);

      for (int x = 0; x <= mx; x++) {
        pref1[x + 1] = (pref1[x] + dp1[l - 1][x]) % MOD;
        pref2[x + 1] = (pref2[x] + dp2[l - 1][x]) % MOD;
      }

      for (int x = 1; x <= mx; x++) {
        int lo = x / 2 + 1;

        dp1[l][x] = ((pref1[x + 1] - pref1[lo]) % MOD + MOD) % MOD;
        dp2[l][x] = ((pref2[x + 1] - pref2[lo]) % MOD + MOD) % MOD;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
