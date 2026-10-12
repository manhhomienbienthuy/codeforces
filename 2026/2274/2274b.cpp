/*!
 * author: manhhomienbienthuy
 * created: 2026-10-12T12:39:24+00:00
 * https://codeforces.com/contest/2274/problem/B
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

    vector<int64_t> a(n);
    for (auto& x : a) cin >> x;

    vector<int64_t> b(n);

    int64_t ans = LLONG_MIN, pref_min = 0, pref_max = 0;
    for (int i = 0; i < n; i++) {
      ans = max({ans, a[i], a[i] - pref_min, a[i] + pref_max});

      int64_t mn = min({a[i], a[i] - pref_min, a[i] + pref_min}),
              mx = max({a[i], a[i] - pref_max, a[i] + pref_max});
      pref_min += mn;
      pref_max += mx;
    }

    cout << ans << '\n';
  }

  return 0;
}
