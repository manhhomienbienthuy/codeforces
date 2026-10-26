/*!
 * author: manhhomienbienthuy
 * created: 2026-10-26T15:12:59+00:00
 * https://codeforces.com/contest/2272/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, x;
    cin >> n >> x;

    vector<int64_t> a(n);
    for (auto& x : a) cin >> x;

    auto check = [&](int64_t k) {
      vector<int64_t> odd;

      for (int i = 0; i < n; i++) {
        bool has = (i >= 1 && a[i] - a[i - 1] <= k) ||
                   (i < n - 1 && a[i + 1] - a[i] <= k);

        if (!has) odd.push_back(a[i]);
      }

      int sz = (int)odd.size(), extra = 0;

      for (int i = 0; i < sz;) {
        extra++;
        i += 1 + (i < sz - 1 && odd[i + 1] - odd[i] <= 2 * k);
      }

      return extra <= x;
    };

    int64_t lo = 1, hi = 1e9;

    while (lo <= hi) {
      int64_t mid = (lo + hi) >> 1;

      if (check(mid)) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    cout << lo << '\n';
  }

  return 0;
}
