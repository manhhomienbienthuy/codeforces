/*!
 * author: manhhomienbienthuy
 * created: 2026-10-31T16:06:05+00:00
 * https://codeforces.com/contest/2278/problem/D
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

    sort(a.begin(), a.end());

    int64_t med = a[n / 2], ans = 0;

    for (int i = 0; i < n; i++) ans += abs(a[i] - med);

    cout << ans << ' ' << a[n - 1] - a[0] << '\n';
  }

  return 0;
}
