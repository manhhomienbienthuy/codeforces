/*!
 * author: manhhomienbienthuy
 * created: 2026-07-20T00:39:22+00:00
 * https://codeforces.com/contest/2247/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k, m;
    cin >> n >> k >> m;

    if (k > m)
      cout << "NO\n";
    else {
      cout << "YES\n";
      cout << m - k + 1;
      for (int i = 1; i < n; i++) cout << ' ' << 1;
      cout << '\n';
    }
  }

  return 0;
}
