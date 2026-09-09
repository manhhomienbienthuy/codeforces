/*!
 * author: manhhomienbienthuy
 * created: 2026-09-09T00:13:59+00:00
 * https://codeforces.com/contest/2260/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int64_t x, y, k;
    cin >> x >> y >> k;

    int64_t d = y - x, ans = k * d;

    for (int64_t a = x; a <= min(x + k - 1, d); a++) ans -= d - d % a;

    cout << ans << '\n';
  }

  return 0;
}
