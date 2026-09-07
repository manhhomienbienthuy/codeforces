/*!
 * author: manhhomienbienthuy
 * created: 2026-09-05T16:52:11+00:00
 * https://codeforces.com/contest/2259/problem/B
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

    int c1 = 0, c2 = 0, c3 = 0;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      if (x & 1)
        c1++;
      else if (!(x % 4))
        c2++;
      else
        c3++;
    }

    cout << max({c1, c2, c3}) << '\n';
  }

  return 0;
}
