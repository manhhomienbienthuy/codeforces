/*!
 * author: manhhomienbienthuy
 * created: 2026-10-08T02:23:24+00:00
 * https://codeforces.com/contest/2275/problem/E
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

    vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<int> v(n + 1), u(n + 1), d(n + 1);

    for (int i = 1; i < n; i++) {
      v[i] = (a[i] == b[i]);
      u[i] = (a[i + 1] == b[i]);
      d[i] = (a[i] == b[i + 1]);
    }

    v[n] = (a[n] == b[n]);

    vector<int64_t> pref(n + 1);
    for (int i = 1; i < n; i++) pref[i + 1] = pref[i] + v[i] + u[i];

    vector<int64_t> suf(n + 2);
    for (int i = n - 1; i >= 1; i--) suf[i] = suf[i + 1] + d[i] + u[i];

    int64_t mx = 0;

    for (int k = 1; k <= n; k++) {
      mx = max(mx, pref[k] + suf[k] + v[n]);
    }

    int64_t ans = 2LL * n - 1 + mx;
    cout << ans << '\n';
  }

  return 0;
}
