/*!
 * author: manhhomienbienthuy
 * created: 2026-11-09T02:08:34+00:00
 * https://codeforces.com/gym/106812/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;

  if (a % c == 0) {
    cout << b % c << '\n';
    return 0;
  }

  int g = gcd(a, c);

  int x = b % c;
  int mn = x - x / g * g, mx = x + (c - 1 - x) / g * g;

  for (int i = mn; i <= mx; i += g) cout << i << ' ';
  cout << '\n';

  return 0;
}
