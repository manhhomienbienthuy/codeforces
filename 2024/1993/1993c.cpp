/*!
 * author: manhhomienbienthuy
 * created: 2026-07-29T02:18:41+00:00
 * https://codeforces.com/contest/1993/problem/C
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

    int mx = 0;
    vector<int> a(n);

    for (int& x : a) {
      cin >> x;
      mx = max(mx, x);
    }

    int l = mx, r = mx + k - 1;

    for (int x : a) {
      int d = (mx - x) % (2 * k);

      int cur_l = d < k ? mx - d : mx + (2 * k - d);
      int cur_r = cur_l + k - 1;

      l = max(l, cur_l);
      r = min(r, cur_r);
    }

    cout << (l <= r ? l : -1) << '\n';
  }

  return 0;
}
