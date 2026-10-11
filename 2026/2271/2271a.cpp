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

    if ((a + b) & 1) {
      cout << (b <= a + 1 ? a + 1 : -1) << '\n';
    } else {
      cout << (b <= a ? a : -1) << '\n';
    }
  }

  return 0;
}
