/*!
 * author: manhhomienbienthuy
 * created: 2026-07-30T01:10:23+00:00
 * https://codeforces.com/gym/106628/problem/G
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int cur =
          int(lower_bound(a.begin(), a.end(), a[i] + d + 1) - a.begin() - i);
      ans = max(ans, cur + (cur < n));
    }

    cout << ans << '\n';
  }

  return 0;
}
