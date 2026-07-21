/*!
 * author: manhhomienbienthuy
 * created: 2026-07-20T00:44:47+00:00
 * https://codeforces.com/contest/2247/problem/C
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
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    int s = 0, cnt = 0;
    bool has0 = false, has1 = false;

    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        s += a[i];
        cnt++;
      } else {
        if (a[i])
          has1 = true;
        else
          has0 = true;
      }
    }

    if (!cnt)
      cout << 0;
    else if (s)
      cout << 2 - (s & 1);
    else
      cout << (has0 && has1 ? 2 : -1);
    cout << '\n';
  }

  return 0;
}
