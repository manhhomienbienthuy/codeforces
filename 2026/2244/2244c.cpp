/*!
 * author: manhhomienbienthuy
 * created: 2026-07-15T00:42:45+00:00
 * https://codeforces.com/contest/2244/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;

    int g = __gcd(x, y);
    bool ok = true;

    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      ok = ok && (x % g == i % g);
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
