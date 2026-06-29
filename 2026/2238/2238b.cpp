/*!
 * author: manhhomienbienthuy
 * created: 2026-06-28T23:55:12+00:00
 * https://codeforces.com/contest/2238/problem/B
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
    // gcd(a, c) = b * k
    int64_t ans = 0;
    for (int b = 1; b <= n; b++) {
      int x = n / b;
      ans += 1ll * x * x;
    }
    cout << ans << '\n';
  }

  return 0;
}
