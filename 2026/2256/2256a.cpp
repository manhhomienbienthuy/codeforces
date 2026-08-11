/*!
 * author: manhhomienbienthuy
 * created: 2026-08-10T05:51:41+00:00
 * https://codeforces.com/contest/2256/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;

    auto [x, y] = minmax({a, b, c});

    cout << min(a + b + c - y, y) - x << '\n';
  }

  return 0;
}
