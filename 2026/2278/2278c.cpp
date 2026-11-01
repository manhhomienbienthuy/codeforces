/*!
 * author: manhhomienbienthuy
 * created: 2026-10-31T15:31:03+00:00
 * https://codeforces.com/contest/2278/problem/C
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

    vector<int> a(n);
    for (int& x : a) cin >> x;

    int l = 0;
    while (l < n && a[l] == 1) l++;

    if (l == n) {
      cout << -1 << '\n';
    } else {
      int ans = accumulate(a.begin(), a.end(), 0);
      bool ok = false;

      for (int i = 1; i < n - 1; i++) {
        if (a[i] >= 2) {
          ok = true;
          break;
        }
      }

      if (ok) {
        cout << ans - 1 << '\n';
      } else {
        cout << ans - n + 1 << '\n';
      }
    }
  }

  return 0;
}
