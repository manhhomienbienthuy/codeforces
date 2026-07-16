/*!
 * author: manhhomienbienthuy
 * created: 2026-07-15T07:29:30+00:00
 * https://codeforces.com/contest/2244/problem/G
 */

#include <bits/stdc++.h>
using namespace std;

struct seg_tree {
  int n;
  vector<int64_t> st;

  seg_tree(int sz) {
    n = 1;
    while (n < sz) n <<= 1;
    st.assign(2 * n, 0);
  }

  void update(int p, int64_t v) {
    p += n - 1;
    st[p] = max(st[p], v);
    for (p >>= 1; p; p >>= 1) {
      st[p] = max(st[p << 1], st[p << 1 | 1]);
    }
  }

  int64_t query(int l, int r, int x, int lx, int rx) {
    if (r < lx || rx < l) return 0;
    if (l <= lx && rx <= r) return st[x];

    int m = (lx + rx) >> 1;
    return max(query(l, r, x << 1, lx, m), query(l, r, x << 1 | 1, m + 1, rx));
  }

  int64_t query(int l, int r) {
    if (l > r) return 0;
    return query(l, r, 1, 1, n);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<pair<int, int64_t>>> add(n + 2);
    vector<int64_t> dp(n + 1, 0);

    seg_tree sg(n);
    int64_t ans = 0;

    for (int j = 1; j <= n; j++) {
      for (auto& [idx, val] : add[j]) {
        sg.update(idx, val);
      }

      int64_t lim = 0ll + j - a[j] - 1;

      int64_t best = 0;
      if (lim >= 1) {
        best = sg.query(1, (int)min(lim, 0ll + n));
      }

      dp[j] = best + a[j];
      ans = max(ans, dp[j]);

      int64_t act = 1ll + j + a[j];
      if (act <= n) {
        add[act].push_back({j, dp[j]});
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
