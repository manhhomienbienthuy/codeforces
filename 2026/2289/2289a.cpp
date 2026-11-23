/*!
 * author: manhhomienbienthuy
 * created: 2026-11-22T10:34:04+00:00
 * https://codeforces.com/contest/2289/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int64_t x;
    cin >> x;

    cout << (x & 1 || x % 4 == 0 ? "YES\n" : "NO\n");
  }

  return 0;
}
