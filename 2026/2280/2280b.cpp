/*!
 * author: manhhomienbienthuy
 * created: 2026-11-07T14:44:02+00:00
 * https://codeforces.com/contest/2280/problem/B
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

    cout << "? 1 " << n << '\n';
    int cnt;
    cin >> cnt;

    if (cnt == n || !cnt) {
      cout << "! NO\n";
      continue;
    }

    cout << "? 1 " << cnt << '\n';
    int r;
    cin >> r;

    cout << (cnt == r ? "! NO\n" : "! YES\n") << '\n';
  }

  return 0;
}
