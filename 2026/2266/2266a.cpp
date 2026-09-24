/*!
 * author: manhhomienbienthuy
 * created: 2026-09-23T01:13:49+00:00
 * https://codeforces.com/contest/2266/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    cout << n - min({a, b, c}) << '\n';
  }

  return 0;
}
