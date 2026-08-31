/*!
 * author: manhhomienbienthuy
 * created: 2026-08-29T14:45:15+00:00
 * https://codeforces.com/contest/2258/problem/B2
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> cnt(m + 1);
    int64_t tot = 0;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
      tot += x;
    }

    vector<int> pref(m + 1);

    for (int i = 1; i <= m; i++) pref[i] = pref[i - 1] + cnt[i];

    vector<int64_t> sum(m + 1);

    for (int x = 1; x <= m; x++) {
      for (int l = x, q = 1; l <= m; l += x, q++) {
        int r = min(m, l + x - 1);
        int num = pref[r] - pref[l - 1];

        sum[x] += 1ll * q * num;
      }
    }

    vector<int64_t> ans(m + 1, tot);

    for (int k = 1, c = 2; k <= m && c <= m; k++, c <<= 1) {
      int64_t best = 0;

      for (int x = 1; x <= m; x++) {
        int64_t cur = sum[x];

        if (x <= m / c) {
          for (int q = c, l = c * x; l <= m; q++, l += x) {
            int r = min(m, l + x - 1);
            int num = pref[r] - pref[l - 1];

            cur -= 1ll * (q - c + 1) * num;
          }

          cur += cnt[c * x];
        }

        best = max(best, cur);
      }

      ans[k] = best;
    }

    for (int k = 1; k <= m; k++) cout << ans[k] << ' ';
    cout << '\n';
  }

  return 0;
}
