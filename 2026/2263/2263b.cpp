/*!
 * author: manhhomienbienthuy
 * created: 2026-09-12T15:30:37+00:00
 * https://codeforces.com/contest/2263/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    if (k < n || k >= 2 * n) {
      cout << -1 << '\n';
      continue;
    }

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) a[0][i] = i + 1;
    for (int i = 1; i < n; i++) a[i][0] = n + i;

    int need = 2 * n - 1 - k;

    for (int i = 1; i <= need; i++) {
      a[i][i] = a[0][i];
      a[0][i] = 0;
    }

    int last = 2 * n - 1;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == 0) {
          a[i][j] = ++last;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << a[i][j] << ' ';
      }
      cout << '\n';
    }
  }

  return 0;
}
