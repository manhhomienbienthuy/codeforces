/*!
 * author: manhhomienbienthuy
 * created: 2026-10-09T06:38:04+00:00
 * https://codeforces.com/gym/106745/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int& x : a) cin >> x;

  int ans = 0, l = 0, r = n - 1;

  for (int k = 1; k <= n; k++) {
    if (l <= r) ans = max({ans, a[l++], a[r--]});
    cout << ans << ' ';
  }

  return 0;
}
