/*!
 * author: manhhomienbienthuy
 * created: 2026-10-26T14:38:04+00:00
 * https://codeforces.com/contest/2272/problem/A
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

    vector<int> a(n);
    for (int& x : a) cin >> x;

    int ii = -1;

    for (int i = 0; i <= n - k; i++) {
      if (a[i] > n - k) {
        ii = i;
        break;
      }
    }

    if (ii == -1) {
      cout << -1 << '\n';
    } else {
      int jj = n - k + 1;

      for (int i = jj + 1; i < n; i++) {
        if (a[i] < a[jj]) jj = i;
      }

      cout << ii + 1 << ' ' << jj + 1 << '\n';
    }
  }

  return 0;
}
