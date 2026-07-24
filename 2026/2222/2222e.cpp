/*!
 * author: manhhomienbienthuy
 * created: 2026-07-24T00:53:41+00:00
 * https://codeforces.com/contest/2222/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  // cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    cout << 0 << '\n';
    cout << "I 0\n";
    int64_t c = 0;
    int k, r;
    cin >> r;

    if (r == 1) {
      // f = AND
      k = 1;
      int sz = 1, r;

      for (int i = 0; i < n; i++) {
        cout << "I " << (1ll << i) << '\n';
        cin >> r;
        if (r > sz) {
          sz = r;
          c |= 1ll << i;
        }
      }

      cout << "A " << k << ' ' << c << '\n';
    } else {
      // f = OR,XOR
      int r;
      int64_t lo = 1, hi = (1ll << n) - 1;

      while (lo <= hi) {
        int64_t mid = (lo + hi) / 2;
        cout << "Q " << mid << '\n';
        cin >> r;
        if (r)
          lo = mid + 1;
        else
          hi = mid - 1;
      }

      c = hi;

      if (__builtin_popcountll(c) > 1) {
        cout << "I " << (c & -c) << '\n';
        cin >> k;
      } else {
        int64_t x = c | 1;
        if (x == 1) x = 3;
        cout << "I " << x << '\n';
        cin >> r;
        cout << "Q " << x << '\n';
        cin >> r;
        if (r)
          k = 2;
        else
          k = 3;
      }

      cout << "A " << k << ' ' << c << '\n';
    }
  }

  return 0;
}
