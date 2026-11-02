/*!
 * author: manhhomienbienthuy
 * created: 2026-10-31T16:14:41+00:00
 * https://codeforces.com/contest/2278/problem/E
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

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (!(i & 1)) a[i] = -a[i];
    }

    sort(a.begin(), a.end(), greater<>());

    int64_t ans = 0;

    for (int i = 0; i < n / 2; i++) ans += a[i] - a[n - i - 1];
    if (n & 1) ans -= a[n / 2];

    cout << ans << '\n';
  }

  return 0;
}
