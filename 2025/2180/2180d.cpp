/*!
 * author: manhhomienbienthuy
 * created: 2026-11-26T02:04:56+00:00
 * https://codeforces.com/contest/2180/problem/D
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

    int64_t l = 0, r = 1e18, prev = 1e18;
    int ans = 0;

    for (int i = 1; i < n; i++) {
      int64_t cur = a[i] - a[i - 1];

      int64_t nl = max(0LL, prev - r), nr = min(cur, prev - l);

      if (nl < nr) {
        ans++;
        l = nl;
        r = nr;
      } else {
        l = 0;
        r = 1e18;
      }

      prev = cur;
    }

    cout << ans << '\n';
  }

  return 0;
}
