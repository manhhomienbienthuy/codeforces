/*!
 * author: manhhomienbienthuy
 * created: 2026-11-04T06:50:13+00:00
 * https://codeforces.com/gym/106787/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long double a, b, c;
  cin >> a >> b >> c;

  long double qa = a / 3.0L, qb = b / 3.0L, qc = c / 10.0L;
  long double q = max({qa, qb, qc});

  cout << fixed << setprecision(10) << q * 3.0L - a << ' ' << q * 3.0L - b
       << ' ' << q * 10.0L - c << '\n';
  return 0;
}
