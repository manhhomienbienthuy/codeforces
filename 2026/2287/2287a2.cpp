/*!
 * author: manhhomienbienthuy
 * created: 2026-11-21T14:48:46+00:00
 * https://codeforces.com/contest/2287/problem/A2
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  // cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int ans = n;

    string s(3 * n, '-');
    for (int i = 0; i < 3 * n; i += 3) s[i] = '+';

    cout << s << '\n';

    int k;
    cin >> k;

    if (k > 0) ans += (k + 2) / 3;

    cout << ans << '\n';
  }

  return 0;
}
