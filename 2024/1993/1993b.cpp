/*!
 * author: manhhomienbienthuy
 * created: 2026-07-29T01:48:43+00:00
 * https://codeforces.com/contest/1993/problem/B
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

    int64_t odd = -1;
    vector<int> a;
    a.reserve(n);

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x & 1)
        odd = max((int)odd, x);
      else
        a.push_back(x);
    }

    if (odd == -1 || a.empty()) {
      cout << 0 << '\n';
      continue;
    }

    sort(a.begin(), a.end());

    int64_t ans = 0;
    bool ok = true;

    for (int x : a) {
      if (x > odd && ok) {
        ok = false;
        ans++;
        odd += x;
      }

      ans++;
      odd += x;
    }

    cout << ans << '\n';
  }

  return 0;
}
