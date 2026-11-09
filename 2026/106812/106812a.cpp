/*!
 * author: manhhomienbienthuy
 * created: 2026-11-09T02:00:30+00:00
 * https://codeforces.com/gym/106812/problem/1
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int64_t ans = 0, fac = n * (n - 1), inv = 2;
  ans += fac / inv;

  if (n >= 3) {
    fac *= n - 2;
    inv *= 3;
    ans += fac / inv;
  }
  if (n >= 4) {
    fac *= n - 3;
    inv *= 4;
    ans += fac / inv;
  }
  if (n >= 5) {
    fac *= n - 4;
    inv *= 5;
    ans += fac / inv;
  }

  cout << ans << '\n';
  return 0;
}
