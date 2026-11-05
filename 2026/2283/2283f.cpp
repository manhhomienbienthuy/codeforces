/*!
 * author: manhhomienbienthuy
 * created: 2026-11-05T03:42:24+00:00
 * https://codeforces.com/contest/2283/problem/F
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
    int n;
    cin >> n;

    vector<int> l(n + 1), r(n + 1);
    for (int i = 2; i <= n; i++) cin >> l[i] >> r[i];

    vector<int> nxt(n + 1, n + 1), p(n + 2);
    iota(p.begin(), p.end(), 0);

    auto find = [&](auto&& self, int x) -> int {
      if (p[x] == x) return x;
      return p[x] = self(self, p[x]);
    };

    for (int i = 2; i <= n; i++) {
      int x = find(find, l[i]);

      while (x <= r[i]) {
        nxt[x] = i;
        p[x] = find(find, x + 1);
        x = find(find, x);
      }
    }

    vector<vector<int>> del(n + 2), qry(n + 1);

    for (int i = 1; i <= n; i++) del[nxt[i]].push_back(i);
    for (int i = 2; i <= n; i++) qry[r[i]].push_back(i);

    fenwick bit(n + 1);
    for (int i = 1; i <= n; i++) bit.add(i, 1);

    int64_t ans = 0;

    for (int ri = 1; ri <= n; ri++) {
      for (int x : del[ri]) bit.add(x, -1);

      for (int i : qry[ri]) ans += bit.query(l[i], r[i]);
    }

    cout << ans << '\n';
  }

  return 0;
}
