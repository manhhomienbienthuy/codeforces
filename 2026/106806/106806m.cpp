/*!
 * author: manhhomienbienthuy
 * created: 2026-11-12T02:14:09+00:00
 * https://codeforces.com/gym/106806/problem/M
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, n;
  cin >> a >> b >> n;

  int g = lcm(a, b), l = 0;

  for (int k = 1; true; k++) {
    if (k % g == 0) {
      l += 8;
    } else if (k % a == 0 || k % b == 0) {
      l += 4;
    } else {
      l += (int)to_string(k).length();
    }

    if (l == n) {
      cout << k << '\n';
      return 0;
    }

    if (l > n) {
      cout << k - 1 << '\n';
      return 0;
    }
  }

  return 0;
}
