/*!
 * author: manhhomienbienthuy
 * created: 2026-07-27T02:45:13+00:00
 * https://codeforces.com/contest/2250/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

struct info {
  int l, r, u, v;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<info> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].l >> a[i].r >> a[i].u >> a[i].v;
    }

    int ans = 0;

    for (int m = 1; m <= n; m++) {
      int k = 0;

      for (int i = 0; i < n && k < m; i++) {
        int rl = k + 1, rr = m - k;

        bool ok = true;

        if (a[i].l <= rl && rl <= a[i].r) ok = false;
        if (a[i].u <= rr && rr <= a[i].v) ok = false;

        if (ok) k++;
      }

      if (k == m) ans = m;
    }

    cout << ans << '\n';
  }

  return 0;
}
