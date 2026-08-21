/*!
 * author: manhhomienbienthuy
 * created: 2026-08-20T00:45:36+00:00
 * https://codeforces.com/gym/106644/problem/M
 */

#include <bits/stdc++.h>
using namespace std;

struct fenwick {
  int n;
  vector<int64_t> bit;

  fenwick(int n) : n(n), bit(n + 1, LLONG_MAX) {}

  void add(int i, int64_t v) {
    for (i++; i <= n; i += i & -i) bit[i] = min(bit[i], v);
  }

  int64_t query(int i) {
    int64_t r = LLONG_MAX;
    for (i++; i > 0; i -= i & -i) r = min(r, bit[i]);
    return r;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int64_t> pref(n + 1);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pref[i + 1] = pref[i] + x;
  }

  vector<int64_t> vals = pref;
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());

  int m = (int)vals.size();

  vector<int> ids(n + 1);

  for (int i = 0; i <= n; i++)
    ids[i] = int(lower_bound(vals.begin(), vals.end(), pref[i]) - vals.begin());

  vector dp(n + 1, vector<int64_t>(n + 1, LLONG_MAX));
  dp[0][0] = 0;

  int64_t ans = LLONG_MAX;

  for (int seg = 1; seg <= n; seg++) {
    fenwick bit1(m), bit2(m);

    auto add_state = [&](int i) {
      if (dp[seg - 1][i] >= LLONG_MAX / 2) return;

      int r = ids[i];

      bit1.add(r, dp[seg - 1][i] - pref[i]);
      bit2.add(m - r, dp[seg - 1][i]);
    };

    add_state(seg - 1);

    for (int i = seg; i <= n; i++) {
      int r = ids[i];

      int64_t best1 = bit1.query(r), best2 = bit2.query(m - r - 1);

      dp[seg][i] =
          min(best2, best1 >= LLONG_MAX / 2 ? LLONG_MAX : pref[i] + best1);

      add_state(i);
    }

    if (seg >= n - k) ans = min(ans, dp[seg][n]);
  }

  cout << ans << '\n';

  return 0;
}
