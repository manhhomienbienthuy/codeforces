/*!
 * author: manhhomienbienthuy
 * created: 2026-07-09T00:53:15+00:00
 * https://codeforces.com/contest/2227/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

struct fenwick {
  int n;
  vector<int64_t> bit;

  fenwick(int n_) : n(n_), bit(n + 1, 0) {}

  void add(int idx, int64_t val) {
    for (; idx <= n; idx += idx & -idx) {
      bit[idx] += val;
    }
  }

  int64_t sum(int idx) {
    int64_t res = 0;

    for (; idx > 0; idx -= idx & -idx) {
      res += bit[idx];
    }

    return res;
  }

  int64_t query(int l, int r) {
    if (l > r) return 0;
    return sum(r) - (l ? sum(l - 1) : 0);
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
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = (int)vals.size();

    auto gid = [&](int x) {
      return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
    };

    fenwick bit_cnt(m);
    fenwick bit_sum(m);

    int64_t ans = 0, d = 0;

    for (int x : a) {
      int id = gid(x);

      int64_t cnt_gt = bit_cnt.query(id + 1, m);
      int64_t sum_gt = bit_sum.query(id + 1, m);

      ans += sum_gt - cnt_gt * x;
      d = max(d, bit_cnt.query(id, m));

      bit_cnt.add(id, 1);
      bit_sum.add(id, x);
    }

    cout << ans + d << '\n';
  }

  return 0;
}
