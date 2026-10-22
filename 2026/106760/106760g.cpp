/*!
 * author: manhhomienbienthuy
 * created: 2026-10-21T03:28:54+00:00
 * https://codeforces.com/gym/106760/problem/G
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
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> left(n + 1);
    vector<int> last(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      int prev = last[a[i]];

      if (prev != 0) {
        left[prev].push_back(i);
      }

      last[a[i]] = i;
    }

    vector<vector<pair<int, int>>> query(n + 1);

    for (int id = 0; id < q; id++) {
      int l, r;
      cin >> l >> r;

      query[l].push_back({r, id});
    }

    vector<int64_t> ans(q);
    fenwick bit(n + 1);

    for (int l = n; l >= 1; l--) {
      for (int r : left[l]) {
        int64_t weight = r - l - 1;
        bit.add(r, weight);
      }

      for (auto [r, id] : query[l]) ans[id] = bit.sum(r);
    }

    for (auto x : ans) cout << x << '\n';
  }

  return 0;
}
