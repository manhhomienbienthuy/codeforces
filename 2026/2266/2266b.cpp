/*!
 * author: manhhomienbienthuy
 * created: 2026-09-23T01:19:34+00:00
 * https://codeforces.com/contest/2266/problem/B
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

    cout << max(a + c - b, b - a) << '\n';
  }

  return 0;
}
