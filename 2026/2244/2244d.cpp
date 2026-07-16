/*!
 * author: manhhomienbienthuy
 * created: 2026-07-15T00:53:42+00:00
 * https://codeforces.com/contest/2244/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    sort(b.begin(), b.end());

    int64_t ans = 0;
    int prev = 0;
    for (int cur : b) {
      int64_t s = 0;
      for (int i = prev; i < cur; i++) {
        s += a[i];
      }
      ans += max(s, -s);
      prev = cur;
    }

    for (int i = prev; i < n; i++) ans += a[i];

    cout << ans << '\n';
  }

  return 0;
}
