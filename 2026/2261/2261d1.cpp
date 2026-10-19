/*!
 * author: manhhomienbienthuy
 * created: 2026-10-17T15:14:47+00:00
 * https://codeforces.com/contest/2261/problem/D1
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    if (n == 1) {
      cout << 0 << '\n';
    } else {
      int k = (n + 1) >> 1;

      cout << k << '\n';
      for (int i = 1; i <= k; i++) cout << i << ' ' << k + i - 1 << '\n';
    }
  }

  return 0;
}
