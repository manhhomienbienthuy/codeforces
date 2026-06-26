/*!
 * author: manhhomienbienthuy
 * created: 2026-06-26T12:05:02+00:00
 * https://codeforces.com/contest/2148/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int x, n;
    cin >> x >> n;
    cout << x * (n & 1) << "\n";
  }

  return 0;
}
