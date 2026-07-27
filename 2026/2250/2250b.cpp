/*!
 * author: manhhomienbienthuy
 * created: 2026-07-27T01:17:25+00:00
 * https://codeforces.com/contest/2250/problem/B
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

    int h1 = k / 2, h2 = (k + 1) / 2;
    if (h1 + h2 + 2 > n)
      cout << -1;
    else {
      for (int i = 0; i <= h1; i++) cout << 0;
      for (int i = 0; i <= h2; i++) cout << 1;

      int r = n - h1 - h2 - 2;

      for (int i = 0; i < r / 2; i++) cout << "01";

      if (r & 1) cout << 0;
    }

    cout << '\n';
  }

  return 0;
}
