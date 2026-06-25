/*!
 * author: manhhomienbienthuy
 * created: 2026-06-24T10:01:13+00:00
 * https://codeforces.com/contest/2035/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    int64_t ans = 1ll * n * m - 1ll * (r - 1) * m - c + 1ll * (n - r) * (m - 1);
    cout << ans << "\n";
  }

  return 0;
}
