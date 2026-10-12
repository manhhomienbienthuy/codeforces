/*!
 * author: manhhomienbienthuy
 * created: 2026-10-12T12:37:19+00:00
 * https://codeforces.com/contest/2274/problem/A
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

    int s = 1, ans = 0;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      ans += x * s;
      s = -s;
    }

    cout << ans << '\n';
  }

  return 0;
}
