/*!
 * author: manhhomienbienthuy
 * created: 2026-09-05T15:29:43+00:00
 * https://codeforces.com/contest/2259/problem/C
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

    vector<int> pos(n, -1);
    int last = -1;

    for (int i = n - 1; i >= 0; i--) {
      pos[i] = last;
      if (a[i] == 1) {
        last = i;
      } else if (a[i] == -1 && last == -1) {
        last = i;
      }
    }

    int mx = 0, l = -1, r = -1;

    for (int i = 0; i < n; i++) {
      if (a[i] != 0) {
        if (pos[i] == -1) {
          if (mx < 1) {
            mx = 1;
            r = i;
          }
        } else {
          int len = pos[i] - i + 1;
          if (len > mx) {
            mx = len;
            l = i;
            r = pos[i];
          }
        }
      }
    }

    for (int i = 0; i < l; i++) cout << max(0, a[i]) << ' ';
    if (l != -1) cout << 1 << ' ';
    for (int i = l + 1; i < r; i++) cout << 0 << ' ';
    if (r != -1) cout << 1 << ' ';
    for (int i = r + 1; i < n; i++) cout << max(0, a[i]) << ' ';
    cout << '\n';
  }

  return 0;
}
