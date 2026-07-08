/*!
 * author: manhhomienbienthuy
 * created: 2026-07-07T01:57:04+00:00
 * https://codeforces.com/contest/2242/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

string calc(int x, int y, int n) {
  vector<int> sx, sy;

  while (x) {
    sx.push_back(x & 1);
    x >>= 1;
  }

  while (y) {
    sy.push_back(y & 1);
    y >>= 1;
  }

  int lx = (int)sx.size(), ly = (int)sy.size();
  string res(n, '0');

  for (int i = 0; i < n; i++) {
    int bx = sx[lx - 1 - (i % lx)], by = sy[ly - 1 - (i % ly)];
    res[i] = bx && by ? '1' : '0';
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int l, r, n;
    cin >> l >> r >> n;

    int x;
    for (x = 1; (x << 1) <= r; x <<= 1);

    if (x > l) {
      int y = max(l, x >> 1);
      cout << calc(x, y, n) << '\n';
    } else {
      for (int y = x; (l & y) == (r & y); y >>= 1) x |= l & y;
      cout << calc(x, x, n) << '\n';
    }
  }
  return 0;
}
