/*!
 * author: manhhomienbienthuy
 * created: 2026-10-10T15:37:09+00:00
 * https://codeforces.com/contest/2271/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int64_t n, m, k;
    cin >> n >> m >> k;

    vector<int64_t> l(n), r(n);

    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

    if (k == 0) {
      cout << r[n - 1] + 1 << '\n';
      continue;
    }

    vector<pair<int64_t, int>> ev;
    ev.reserve(4 * n);

    int64_t val = 0;

    for (int i = 0; i < n; i++) {
      int64_t lo = max<int64_t>(l[i], 1);
      int64_t hi = min(r[i], m);

      if (lo <= hi) val += hi - lo + 1;

      ev.push_back({l[i] - m, 1});
      ev.push_back({r[i] - m + 1, -1});
      ev.push_back({l[i], -1});
      ev.push_back({r[i] + 1, 1});
    }

    auto has = [&](int64_t x) -> int {
      int pos = int(upper_bound(l.begin(), l.end(), x) - l.begin()) - 1;
      return pos >= 0 && x <= r[pos];
    };

    int d = has(m + 1) - has(1);

    sort(ev.begin(), ev.end());

    vector<pair<int64_t, int>> evt;

    for (auto [x, add] : ev) {
      if (x <= 1) continue;

      if (!evt.empty() && evt.back().first == x)
        evt.back().second += add;
      else
        evt.push_back({x, add});
    }

    int64_t ans = -1, cur = 1;

    if (val == k) ans = cur;

    for (auto [nxt, add] : evt) {
      if (ans != -1) break;

      int64_t len = nxt - cur;

      if (d == 1 && val < k && k <= val + len) {
        ans = cur + k - val;
        break;
      }

      if (d == -1 && val > k && k >= val - len) {
        ans = cur + val - k;
        break;
      }

      val += 1LL * d * len;
      cur = nxt;
      d += add;

      if (val == k) {
        ans = cur;
        break;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
