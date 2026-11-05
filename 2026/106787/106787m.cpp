/*!
 * author: manhhomienbienthuy
 * created: 2026-11-05T05:05:44+00:00
 * https://codeforces.com/gym/2283/problem/M
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;

  vector<int64_t> t(n);
  for (int64_t& x : t) cin >> x;

  sort(t.begin(), t.end());

  int mx_grp = s - n + 1;

  auto ok = [&](double tm) {
    if ((double)t.back() > tm) return false;

    int need1 =
        n - (int)(upper_bound(t.begin(), t.end(), tm * 0.6) - t.begin());

    int need2 =
        n - (int)(upper_bound(t.begin(), t.end(), tm * 0.3) - t.begin());

    for (int a : {need1, need1 + 1, need1 + 2, n}) {
      if (a < need1 || a > n) continue;

      int b = 0;

      if (a < n) b = max(1, (max(0, need2 - a) + 1) / 2);

      if (a + b <= mx_grp && a + 2 * b <= n && a + 2 * b >= need2) {
        return true;
      }
    }

    return false;
  };

  double lo = 0, hi = (double)t.back() / 0.3;

  for (int it = 0; it < 100; it++) {
    double mid = (lo + hi) / 2;

    if (ok(mid))
      hi = mid;
    else
      lo = mid;
  }

  cout << fixed << setprecision(10) << hi << '\n';

  return 0;
}
