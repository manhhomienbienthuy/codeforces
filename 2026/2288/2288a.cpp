/*!
 * author: manhhomienbienthuy
 * created: 2026-11-24T00:30:21+00:00
 * https://codeforces.com/contest/2288/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int x;
    cin >> x;

    int ans = x;

    for (int charge = 0; charge <= x; charge++) {
      int dam = charge + 1, s = 0, cnt = charge;

      while (s < x && dam > 1) {
        s += dam--;
        cnt++;
      }

      if (s < x) cnt += x - s;

      ans = min(ans, cnt);
    }

    cout << ans << '\n';
  }

  return 0;
}
