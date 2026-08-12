/*!
 * author: manhhomienbienthuy
 * created: 2026-08-11T14:34:58+00:00
 * https://codeforces.com/contest/2252/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;

  while (tt--) {
    int n;
    cin >> n;

    vector<int64_t> a(n);
    for (int64_t& x : a) cin >> x;

    vector<int64_t> d(n), ans(n);

    ans[0] = a[0];

    for (int i = 1; i < n; i++) d[i] = a[i] - a[i - 1];

    for (int l = 1, r; l < n; l = r + 1) {
      for (r = l; r < n - 1 && (a[r - 1] & 1LL) == (a[r + 1] & 1LL); r++);

      sort(d.begin() + l, d.begin() + r + 1);

      for (int i = l; i <= r; i++) ans[i] = ans[i - 1] + d[i];
    }

    for (int64_t x : ans) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}
