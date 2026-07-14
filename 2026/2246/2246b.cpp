/*!
 * author: manhhomienbienthuy
 * created: 2026-07-13T00:30:30+00:00
 * https://codeforces.com/contest/2246/problem/B
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

    if (n == 1) {
      cout << 3 << '\n';
      continue;
    }

    if (n == 2) {
      cout << -1 << '\n';
      continue;
    }

    cout << "3 2 1";
    int64_t x = 6;
    for (int i = 4; i <= n; i++) {
      cout << ' ' << x;
      x <<= 1;
    }
    cout << '\n';
  }

  return 0;
}
