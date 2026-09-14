/*!
 * author: manhhomienbienthuy
 * created: 2026-09-12T15:39:37+00:00
 * https://codeforces.com/contest/2263/problem/C2
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int k = 1; k <= n; k++) cin >> a[k];

    vector<int> diff(n + 1), req(n);

    for (int k = 1; k <= n; k++) {
      int64_t l = 1ll * a[k] * k;
      int64_t r = 1ll * (a[k] + 1) * k - 1;

      if (l < n) {
        r = min<int64_t>(r, n - 1);

        diff[l]++;
        diff[r + 1]--;
      }

      for (int q = 0; q < a[k]; q++) {
        int l = q * k;
        int r = min(n - 1, (q + 1) * k - 1);
        req[r] = max(req[r], l + 1);
      }
    }

    vector<int> dp(n + 1);
    dp[0] = 1;

    int sum = 1, ban = 0, ptr = 0;

    for (int i = 0; i < n; i++) {
      ban += diff[i];

      if (ban == 0) {
        dp[i + 1] = sum;
        sum += dp[i + 1];
        if (sum >= MOD) sum -= MOD;
      }

      while (ptr < req[i]) {
        sum -= dp[ptr];
        if (sum < 0) sum += MOD;
        ptr++;
      }
    }

    cout << sum << '\n';
  }

  return 0;
}
