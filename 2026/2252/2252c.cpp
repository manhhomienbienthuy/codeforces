/*!
 * author: manhhomienbienthuy
 * created: 2026-08-11T10:49:51+00:00
 * https://codeforces.com/contest/2256/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

struct fenwick {
  int n;
  vector<int64_t> bit;

  fenwick(int n) : n(n), bit(n + 1, 0) {}

  void add(int i, int64_t v) {
    for (i++; i <= n; i += i & -i) bit[i] += v;
  }

  int64_t sum(int i) {
    int64_t r = 0;
    for (i++; i > 0; i -= i & -i) r += bit[i];
    return r;
  }

  int64_t query(int l, int r) {
    if (l > r) return 0;
    return sum(r) - sum(l - 1);
  }

  int kth(int64_t k) {
    int pos = 0;

    int pw = 1;
    while ((pw << 1) <= n) pw <<= 1;

    for (; pw; pw >>= 1) {
      int nxt = pos + pw;

      if (nxt <= n && bit[nxt] < k) {
        k -= bit[nxt];
        pos = nxt;
      }
    }

    return pos;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int& x : v) cin >> x;

    vector<vector<int>> a(n, vector<int>(m));
    vector<int> vals(n * m);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        vals[i * m + j] = a[i][j];
      }
    }

    sort(vals.begin(), vals.end(), greater<int>());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int sz = (int)vals.size();

    fenwick bit_cnt(sz), bit_sum(sz);

    int64_t total = 0, ans = m;

    for (int row = n - 1; row >= 0; row--) {
      for (int x : a[row]) {
        int id = int(lower_bound(vals.begin(), vals.end(), x, greater<int>()) -
                     vals.begin());

        bit_cnt.add(id, 1);
        bit_sum.add(id, x);

        total += x;
      }

      if (total < v[row]) {
        continue;
      }

      int pos = bit_sum.kth(v[row]);

      int64_t value = vals[pos],
              need = bit_cnt.sum(pos) - (bit_sum.sum(pos) - v[row]) / value;

      ans = min(ans, need);
    }

    cout << ans << '\n';
  }

  return 0;
}
