/*!
 * author: manhhomienbienthuy
 * created: 2026-08-08T13:29:07+00:00
 * https://codeforces.com/contest/2254/problem/E
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

    multiset<int64_t> b;
    for (int i = 0; i < n; i++) {
      int64_t x;
      cin >> x;
      b.insert(x);
    }

    vector<int64_t> a(n);
    int64_t cur = 0;
    bool ok = true;

    for (int i = 0; i < n; i++) {
      auto p = b.lower_bound(1 - cur);

      if (p == b.end()) {
        ok = false;
        break;
      }

      cur += *p;
      a[i] = cur;
      b.erase(p);
    }

    if (!ok) {
      cout << -1 << '\n';
    } else {
      for (int64_t x : a) cout << x << ' ';
      cout << '\n';
    }
  }

  return 0;
}
