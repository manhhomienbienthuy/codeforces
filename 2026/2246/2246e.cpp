/*!
 * author: manhhomienbienthuy
 * created: 2026-07-14T01:41:37+00:00
 * https://codeforces.com/contest/2246/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    cout << 1 << '\n';

    int o;
    cin >> o;

    if (o == 0) {
      // v is even
      cout << 0 << ' ' << 1 << '\n';

      int r;
      cin >> r;
      cout << (r & 1) << '\n';
    } else if (o == 1) {
      // v is 0,1 or v is odd
      int m0 = (rng() & ((1 << 30) - 1)) | 1,
          m1 = (rng() & ((1 << 30) - 1)) & ~1;
      // if interactor generate v = m0 ^ m1, this will fail
      cout << m0 << ' ' << m1 << '\n';

      int r;
      cin >> r;

      if (r == m0 || r == (m0 ^ 1)) {
        cout << 0 << '\n';
      } else if (r == m1 || r == (m1 ^ 1)) {
        cout << 1 << '\n';
      } else {
        cout << (r & 1) << '\n';
      }
    } else {
      // v has many bits
      cout << o << ' ' << 0 << '\n';
      int r;
      cin >> r;
      cout << (r < 2 ? 0 : 1) << '\n';
    }
  }

  return 0;
}
