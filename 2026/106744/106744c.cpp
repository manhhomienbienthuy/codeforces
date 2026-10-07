/*!
 * author: manhhomienbienthuy
 * created: 2026-10-07T06:49:38+00:00
 * https://codeforces.com/gym/106744/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;

  while (q--) {
    int a, b;

    cin >> a >> b;

    int64_t lim = (a + b - 1) / b;

    int64_t ans = (lim - 1) * a - lim * (lim - 1) / 2 * b + a;

    cout << ans << '\n';
  }

  return 0;
}
