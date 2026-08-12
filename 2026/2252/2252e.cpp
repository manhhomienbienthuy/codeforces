/*!
 * author: manhhomienbienthuy
 * created: 2026-08-12T04:08:34+00:00
 * https://codeforces.com/contest/2252/problem/E
 * This solution is derived from editorial
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;

  while (tt--) {
    int64_t n;
    cin >> n;

    // dp[c_less][a_less][need]
    // c_less: c prefix < n prefix
    // a_less: a prefix < c prefix
    // need: value of a[i] & c[i] (= a[i-1] ^ c[i-1])
    vector dp(2, vector(2, vector<int64_t>(2, 0)));
    dp[0][0][0] = 1;

    for (int i = 60; i >= 0; i--) {
      int ni = (n >> i) & 1;
      vector ndp(2, vector(2, vector<int64_t>(2, 0)));

      for (int c_less = 0; c_less < 2; c_less++) {
        for (int a_less = 0; a_less < 2; a_less++) {
          for (int need = 0; need < 2; need++) {
            if (!dp[c_less][a_less][need]) continue;

            int64_t cur = dp[c_less][a_less][need];

            for (int ai = 0; ai < 2; ai++) {
              for (int ci = 0; ci < 2; ci++) {
                if ((ai & ci) != need) continue;
                if (!c_less && ci > ni) continue;
                if (!a_less && ai > ci) continue;

                int nc = c_less || (ci < ni);
                int na = a_less || (ai < ci);
                int nn = ai ^ ci;

                ndp[nc][na][nn] += cur;
              }
            }
          }
        }
      }

      dp = move(ndp);
    }

    int64_t ans = (dp[0][1][0] + dp[1][1][0]) % MOD;
    cout << ans << '\n';
  }

  return 0;
}
