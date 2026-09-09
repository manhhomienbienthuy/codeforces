/*!
 * author: manhhomienbienthuy
 * created: 2026-09-09T06:48:44+00:00
 * https://codeforces.com/contest/2260/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int x, y;
    cin >> x >> y;

    int s = x + y, a = 0;

    for (int bit = 29; bit >= 0; bit--) {
      int val = 1 << bit;

      if ((s & val) && a + val <= x) a += val;
    }

    cout << s << ' ' << x - a << '\n';
  }

  return 0;
}
