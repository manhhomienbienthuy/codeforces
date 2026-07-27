/*!
 * author: manhhomienbienthuy
 * created: 2026-07-27T01:09:25+00:00
 * https://codeforces.com/contest/2250/problem/A
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

    int odd = 0, even = INT_MAX;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      if (i & 1)
        odd = max(odd, x);
      else
        even = min(even, x);
    }

    cout << (!(n & 1) && even - odd > 1 ? "YES\n" : "NO\n");
  }

  return 0;
}
