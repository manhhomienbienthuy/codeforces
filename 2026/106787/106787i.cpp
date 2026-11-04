/*!
 * author: manhhomienbienthuy
 * created: 2026-11-04T06:23:08+00:00
 * https://codeforces.com/gym/106787/problem/I
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;

  int64_t nn = n * n, mn = LLONG_MAX, mnx = 1, mny = nn;

  for (int64_t i = 1; i <= n; i++) {
    if (nn % i == 0) {
      int64_t j = nn / i;

      if (i == j) continue;

      if (i + j < mn) {
        mn = i + j;
        mnx = i;
        mny = j;
      }
    }
  }

  cout << mnx + n << ' ' << mny + n << '\n';
  return 0;
}
