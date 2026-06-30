/*!
 * author: manhhomienbienthuy
 * created: 2026-06-30T02:14:53+00:00
 * https://codeforces.com/contest/2227/problem/G
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
    vector<int64_t> pref(n + 1);
    int s = 1;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      pref[i + 1] = pref[i] + s * x;
      s *= -1;
    }

    vector<int64_t> even, odd;
    for (int i = 0; i <= n; i++) {
      if (i & 1)
        odd.push_back(pref[i]);
      else
        even.push_back(pref[i]);
    }
    sort(even.begin(), even.end());

    int64_t ans = 0;
    for (auto x : odd) {
      ans += lower_bound(even.begin(), even.end(), x) - even.begin();
    }
    cout << ans << '\n';
  }

  return 0;
}
