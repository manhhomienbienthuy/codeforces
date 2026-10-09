/*!
 * author: manhhomienbienthuy
 * created: 2026-10-07T15:51:56+00:00
 * https://codeforces.com/contest/2275/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

struct lab {
  int64_t s;
  int64_t p;
  int type;  // 0 = good, 1 = fixed, 2 = bad
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    int64_t k;
    cin >> n >> k;

    vector<lab> v(n);

    int64_t lo = LLONG_MIN, hi = LLONG_MIN;

    for (int i = 0; i < n; i++) {
      int64_t a, b, c, s;

      cin >> a >> b >> c;
      s = a + b + c;

      hi = max(hi, s + k);

      if (a == b && b == c) {
        v[i] = {s, 0, 1};
      } else if (a <= b && b <= c) {
        int64_t p = min(b - a + 1, c - b + 1);
        v[i] = {s, p, 2};
      } else {
        v[i] = {s, 0, 0};
      }
    }

    auto ok = [&](int64_t target) {
      int64_t need = 0;

      for (auto& x : v) {
        if (x.type == 0) {
          if (target > x.s) {
            need += target - x.s;
          }
        } else if (x.type == 1) {
          if (target > x.s) {
            return false;
          }
        } else {
          if (target > x.s) {
            need += (target - x.s) + 2 * x.p;
          }
        }

        if (need > k) {
          return false;
        }
      }

      return need <= k;
    };

    while (lo <= hi) {
      int64_t mid = (lo + hi) >> 1;

      if (ok(mid)) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    cout << hi << '\n';
  }

  return 0;
}
