/*!
 * author: manhhomienbienthuy
 * created: 2026-11-07T14:50:34+00:00
 * https://codeforces.com/contest/2280/problem/C
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

    vector<int> d(n - 1);
    int lo = 0, hi = 0;

    for (int i = 0; i + 1 < n; i++) {
      d[i] = abs(a[i] - a[i + 1]);
      hi = max(hi, d[i]);
    }

    auto check = [&](int m) -> bool {
      int l = -1, r = -1;

      for (int i = 0; i + 1 < n; i++) {
        if (d[i] > m) {
          if (l == -1) l = i;
          r = i;
        }
      }

      if (l == -1) return true;

      auto ok = [&](int p, int q) {
        if (p > 0 && abs(a[p - 1] - 2 * a[q]) > m) return false;
        if (q + 1 < n && abs(2 * a[p] - a[q + 1]) > m) return false;
        return true;
      };

      if (l < r) {
        for (int i = l + 1; i < r; i++)
          if (2 * d[i] > m) return false;

        return ok(l + 1, r);
      }

      for (int i = l; i >= 0; i--) {
        if (i < l && 2 * d[i] > m) break;
        if (ok(i, l)) return true;
      }

      for (int i = l + 1; i < n; i++) {
        if (i > l + 1 && 2 * d[i - 1] > m) break;
        if (ok(l + 1, i)) return true;
      }

      return false;
    };

    while (lo <= hi) {
      int mid = (lo + hi) >> 1;

      if (check(mid))
        hi = mid - 1;
      else
        lo = mid + 1;
    }

    cout << lo << '\n';
  }

  return 0;
}
