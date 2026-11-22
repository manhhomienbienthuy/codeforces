/*!
 * author: manhhomienbienthuy
 * created: 2026-11-21T14:59:12+00:00
 * https://codeforces.com/contest/2287/problem/B
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
    int64_t s = 0;

    for (int& x : a) {
      cin >> x;
      s += x;
    }

    auto check = [&](int64_t m) {
      int64_t need = 0, pref = 0;

      for (int i = 0; i < n; i++) {
        pref += a[i];
        int64_t suf = s - pref + a[i];

        bool left = i > 0 && pref > m, right = i < n - 1 && suf > m;
        if (left || right) need += a[i];
      }

      return need <= m;
    };

    int64_t lo = 0, hi = s;

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
