/*!
 * author: manhhomienbienthuy
 * created: 2026-07-01T00:59:03+00:00
 * https://codeforces.com/contest/2241/problem/A
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
    cout << (x % y == 0 ? "YES\n" : "NO\n");
  }

  return 0;
}
