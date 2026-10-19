/*!
 * author: manhhomienbienthuy
 * created: 2026-10-19T00:14:20+00:00
 * https://codeforces.com/gym/106759/problem/C
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

    vector<int> a(n);
    for (int& x : a) cin >> x;

    int64_t ans = 0, d = LLONG_MAX, pref = 0;

    for (int i = 0; i < n; i++) {
      ans += 1LL * a[i] * (n - i);
      d = min(d, 1LL * a[i] * i - pref);
      pref += a[i];
    }

    cout << ans + d << '\n';
  }

  return 0;
}
