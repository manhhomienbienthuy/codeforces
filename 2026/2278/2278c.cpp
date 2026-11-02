/*!
 * author: manhhomienbienthuy
 * created: 2026-10-31T15:31:03+00:00
 * https://codeforces.com/contest/2278/problem/C
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

    vector<int> a(n);
    for (int& x : a) cin >> x;

    int ans = accumulate(a.begin(), a.end(), 0);

    if (ans == n) {
      cout << -1 << '\n';
      continue;
    }

    bool ok = false;
    for (int i = 1; !ok && i < n - 1; i++) ok = (a[i] >= 2);

    cout << ans - (ok ? 1 : n - 1) << '\n';
  }

  return 0;
}
