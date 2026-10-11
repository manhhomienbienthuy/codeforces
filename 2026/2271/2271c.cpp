/*!
 * author: manhhomienbienthuy
 * created: 2026-10-10T15:28:35+00:00
 * https://codeforces.com/contest/2271/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int m = 1;
    while (m <= n) m <<= 1;

    cout << 2 * m - 1 << '\n';

    for (int i = 0; i < m - 1; i++) {
      int g1 = i ^ (i >> 1), g2 = (i + 1) ^ ((i + 1) >> 1);

      cout << 0 << ' ' << (g1 ^ g2) << ' ';
    }

    cout << 0 << '\n';
  }

  return 0;
}
