/*!
 * author: manhhomienbienthuy
 * created: 2026-07-30T01:08:00+00:00
 * https://codeforces.com/gym/106628/problem/E
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

    int64_t ans = 0;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ans += x;
    }

    cout << ans << '\n';
  }

  return 0;
}
