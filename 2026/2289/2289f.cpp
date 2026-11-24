/*!
 * author: manhhomienbienthuy
 * created: 2026-11-24T05:00:49+00:00
 * https://codeforces.com/contest/2289/problem/F
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

    vector<char> sq_free(n + 1, true);
    sq_free[0] = false;

    for (int p = 2; 1LL * p * p <= n; p++) {
      int sq = p * p;

      for (int x = sq; x <= n; x += sq) {
        sq_free[x] = false;
      }
    }

    vector<int> cnt(n + 1);

    for (int k = 1; k <= n; k++) {
      if (!sq_free[k]) continue;

      int q = n / k, u = (int)sqrt(q);
      cnt[k] = u;
    }

    int lim = (int)sqrt(n);

    while ((lim + 1) * (lim + 1) <= n) lim++;
    while (lim * lim > n) lim--;

    int64_t ans = 0;

    for (int b = 1; b <= lim; b++) {
      for (int a = 1; a <= b; a++) {
        int ab = a * b;

        if (!cnt[ab]) continue;

        int mx_c = n / b;

        for (int c = b; c <= mx_c; c++) {
          int ac = a * c, bc = b * c;

          if (!cnt[ac] || !cnt[bc]) continue;

          int mul;

          if (a == c)
            mul = 1;
          else if (a == b || b == c)
            mul = 3;
          else
            mul = 6;

          ans += 1LL * mul * cnt[ab] * cnt[ac] * cnt[bc];
        }
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
