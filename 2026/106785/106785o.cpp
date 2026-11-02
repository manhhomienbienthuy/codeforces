/*!
 * author: manhhomienbienthuy
 * created: 2026-11-02T10:07:57+00:00
 * https://codeforces.com/gym/106785/problem/O
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m - 1; i++) {
      for (int j = 0; j < n; j++) cout << 1 << ' ';
      cout << '\n';
    }

    for (int i = 0; i < n - 1; i++) cout << 1 << ' ';
    cout << 6 << '\n';
  }

  return 0;
}
