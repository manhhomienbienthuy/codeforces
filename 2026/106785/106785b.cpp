/*!
 * author: manhhomienbienthuy
 * created: 2026-11-03T11:43:18+00:00
 * https://codeforces.com/gym/106785/problem/B
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

    if (n < m) swap(n, m);

    if (m == 1) {
      if (n < 4) {
        cout << 0 << '\n';
      } else {
        cout << n * (n - 1) / 2 - 3 << '\n';
      }
    } else if (m == 2) {
      cout << 3 * (n - 2) + 2 << '\n';
    } else {
      cout << 4 << '\n';
    }
  }

  return 0;
}
