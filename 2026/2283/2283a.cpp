/*!
 * author: manhhomienbienthuy
 * created: 2026-11-04T14:46:47+00:00
 * https://codeforces.com/contest/2283/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int l, r;
    cin >> l >> r;

    if (l > 0 || r < 0) {
      cout << r - l << '\n';
      continue;
    }

    cout << max(0, abs(r + l) - 1) << '\n';
  }

  return 0;
}
