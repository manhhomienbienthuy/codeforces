/*!
 * author: manhhomienbienthuy
 * created: 2026-08-10T00:57:10+00:00
 * https://codeforces.com/contest/2253/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int64_t dist(int64_t x, int64_t y, int64_t px, int64_t py) {
  int64_t dx = (int64_t)x - px;
  int64_t dy = (int64_t)y - py;
  return dx * dx + dy * dy;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int64_t x, y;
    cin >> x >> y;

    int64_t best = dist(x, y, 0, 0);

    int bestL = 0;
    int64_t bestP = 0;

    for (int L = 1;; L++) {
      int64_t T = 1LL * L * (L + 1) / 2;

      if (T > x + y) {
        break;
      }

      int64_t lo = max(0LL, T - y);
      int64_t hi = min(T, x);

      if (lo > hi) {
        continue;
      }

      long double p0 = (x - y + T) / 2.0L;

      vector<int64_t> cand;

      int64_t f = (int64_t)floor(p0);
      int64_t c = (int64_t)ceil(p0);

      cand.push_back(min(hi, max(lo, f)));
      cand.push_back(min(hi, max(lo, c)));

      for (int64_t p : cand) {
        int64_t q = T - p;

        int64_t cur = dist(x, y, p, q);

        if (cur < best) {
          best = cur;
          bestL = L;
          bestP = p;
        }
      }
    }

    int L = bestL;
    int64_t p = bestP;

    string ans(L, 'Y');

    for (int w = L; w >= 1; w--) {
      if (p >= w) {
        p -= w;
        ans[L - w] = 'X';
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
