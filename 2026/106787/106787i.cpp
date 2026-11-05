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

  int64_t nn = n * n;

  for (int64_t i = n - 1; i >= 1; i--) {
    if (nn % i == 0) {
      cout << i + n << ' ' << nn / i + n << '\n';
      return 0;
    }
  }
}
