/*!
 * author: manhhomienbienthuy
 * created: 2026-09-14T04:20:19+00:00
 * https://codeforces.com/contest/2264/problem/B
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

    vector<int> a(n);

    priority_queue<int> pref;

    int64_t s = 0;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i < m - 1) {
        s += a[i];
        pref.push(a[i]);
      }
    }

    int64_t ans = LLONG_MIN;
    for (int i = m - 1; i < n; i++) {
      ans = max(ans, 1ll * m * a[i] - s);

      pref.push(a[i]);
      s += a[i] - pref.top();
      pref.pop();
    }

    cout << ans << '\n';
  }

  return 0;
}
