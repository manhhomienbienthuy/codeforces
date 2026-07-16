/*!
 * author: manhhomienbienthuy
 * created: 2026-07-15T00:37:12+00:00
 * https://codeforces.com/contest/2244/problem/B
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

    int64_t s = 0;
    bool ok = true;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      s += x - i - 1;
      ok = ok && (s >= 0);
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
