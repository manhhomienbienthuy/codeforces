/*!
 * author: manhhomienbienthuy
 * created: 2026-11-06T14:38:36+00:00
 * https://codeforces.com/contest/2284/problem/A1
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int64_t n;
    cin >> n;

    int64_t x = n / 2, y = n - x;

    cout << x * y << '\n';
  }

  return 0;
}
