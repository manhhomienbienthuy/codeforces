/*!
 * author: manhhomienbienthuy
 * created: 2026-09-26T14:40:18+00:00
 * https://codeforces.com/contest/2269/problem/A
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

    int64_t ans = (1ll << (n - k + 1)) + 2ll * (k - 1);

    cout << ans << '\n';
  }

  return 0;
}
