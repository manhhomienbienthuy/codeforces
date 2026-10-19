/*!
 * author: manhhomienbienthuy
 * created: 2026-10-19T03:51:54+00:00
 * https://codeforces.com/gym/106759/problem/F
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

    vector<int> a(n);
    for (int& x : a) cin >> x;

    multiset<int> vals;

    auto ok = [&]() {
      if (vals.size() <= 2) return true;

      int v1 = *vals.begin(), v2 = *next(vals.begin()),
          v3 = *next(vals.rbegin()), v4 = *(vals.rbegin());

      return (v3 - v1 <= k) || (v4 - v2 <= k);
    };

    int ans = 0, l = 0;

    for (int r = 0; r < n; r++) {
      vals.insert(a[r]);

      while (!ok()) {
        auto it = vals.find(a[l]);
        vals.erase(it);
        l++;
      }

      ans = max(ans, r - l + 1);
    }

    cout << ans << '\n';
  }

  return 0;
}
