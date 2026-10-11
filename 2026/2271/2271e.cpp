/*!
 * author: manhhomienbienthuy
 * created: 2026-10-10T15:56:22+00:00
 * https://codeforces.com/contest/2271/problem/E
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

    vector<int> cnt(n + 1);
    set<int> vals;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
      vals.insert(x);
    }

    int ans = 0;

    while (!vals.empty()) {
      while (!vals.empty() && *vals.begin() <= k) {
        int x = *vals.begin();

        k += cnt[x];
        ans += cnt[x];

        cnt[x] = 0;
        vals.erase(vals.begin());
      }

      if (vals.empty()) break;

      int reach = k + 1;

      for (int x : vals) {
        if (x > reach) break;
        reach += cnt[x];
      }

      auto lo = vals.upper_bound(reach);
      auto hi = vals.upper_bound(min(n, 2 * reach));

      int x;

      if (lo != hi) {
        x = *prev(hi);
      } else {
        x = *vals.rbegin();
      }

      if (!--cnt[x]) vals.erase(x);

      int y = (x + 1) >> 1;

      if (!cnt[y]) vals.insert(y);

      cnt[y] += 2;

      k++;
      ans++;
    }

    cout << ans << '\n';
  }

  return 0;
}
