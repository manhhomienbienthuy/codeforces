/*!
 * author: manhhomienbienthuy
 * created: 2026-11-09T07:39:20+00:00
 * https://codeforces.com/gym/106816/problem/1
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> t;

  if (n & 1) {
    cout << 1LL * t * 2 + 1LL * t * (3 + n) * (n / 2) << '\n';
  } else {
    cout << 1LL * t * n * (n / 2 + 1) << '\n';
  }
  return 0;
}
