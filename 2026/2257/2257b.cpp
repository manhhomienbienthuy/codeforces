/*!
 * author: manhhomienbienthuy
 * created: 2026-08-18T01:34:50+00:00
 * https://codeforces.com/contest/2257/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    int64_t sa = n - 1, sb = m - 1;
    int x;

    cin >> x;
    sa += x;
    for (int i = 1; i < n; i++) {
      int x;
      cin >> x;
    }

    cin >> x;
    sb += x;
    for (int i = 1; i < m; i++) {
      int x;
      cin >> x;
    }

    cout << 1 + (sa < sb) << '\n';
  }

  return 0;
}
