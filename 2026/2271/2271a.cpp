/*!
 * author: manhhomienbienthuy
 * created: 2026-10-10T15:04:32+00:00
 * https://codeforces.com/contest/2271/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << (a + 1 < b ? -1 : a + ((a + b) & 1)) << '\n';
  }

  return 0;
}
