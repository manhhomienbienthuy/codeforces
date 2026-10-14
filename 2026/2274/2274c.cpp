/*!
 * author: manhhomienbienthuy
 * created: 2026-10-13T02:33:39+00:00
 * https://codeforces.com/contest/2274/problem/C
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

    auto ok = [&](int mx) {
      int64_t sum = 0;

      for (int sz = 1; sz <= mx; sz++) {
        sum += 1LL * sz * (mx / sz);
      }

      return sum >= n;
    };

    int lo = 1, hi = n;

    while (lo <= hi) {
      int mid = (lo + hi) >> 1;

      if (ok(mid)) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    int cost = lo;

    vector<int> cnt(cost + 1);

    for (int sz = 2; sz <= cost; sz++) {
      cnt[sz] = min(cost / sz, n / sz);
      n -= cnt[sz] * sz;
    }

    cnt[1] = n;

    vector<int> a;
    int bag = 1;

    for (int sz = 1; sz <= cost; sz++) {
      for (int j = 0; j < cnt[sz]; j++, bag++) {
        for (int z = 0; z < sz; z++) a.push_back(bag);
      }
    }

    cout << cost << '\n';
    for (int x : a) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}
