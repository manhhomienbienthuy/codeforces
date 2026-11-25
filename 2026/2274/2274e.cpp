/*!
 * author: manhhomienbienthuy
 * created: 2026-11-25T04:51:36+00:00
 * https://codeforces.com/contest/2274/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

struct fenwick_2d {
  int n;
  vector<int64_t> bit;

  fenwick_2d(int n) : n(n), bit((n + 1) * (n + 1)) {}

  int id(int i, int j) const { return i * (n + 1) + j; }

  void add(int i, int j, int64_t val) {
    for (i++; i <= n; i += i & -i) {
      for (int y = j + 1; y <= n; y += y & -y) {
        bit[id(i, y)] += val;
      }
    }
  }

  int64_t sum(int i, int j) const {
    if (i < 0 || j < 0) return 0;

    int64_t res = 0;

    for (i++; i > 0; i -= i & -i) {
      for (int y = j + 1; y > 0; y -= y & -y) {
        res += bit[id(i, y)];
      }
    }

    return res;
  }

  int64_t query(int r1, int c1, int r2, int c2) const {
    if (r1 > r2 || c1 > c2) return 0;

    return sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) +
           sum(r1 - 1, c1 - 1);
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

    vector a(n, vector<int64_t>(n)), d(n, vector<int64_t>(n));

    for (auto& row : a) {
      for (int64_t& x : row) cin >> x;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int64_t b;
        cin >> b;
        d[i][j] = b - a[i][j];
      }
    }

    int sz = n - 1;

    vector<int64_t> c(sz * sz);

    auto id = [&](int i, int j) { return i * sz + j; };

    fenwick_2d bit(sz);

    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        int64_t val = d[i][j] - d[i + 1][j] - d[i][j + 1] + d[i + 1][j + 1];

        c[id(i, j)] = val;
        bit.add(i, j, val * val);
      }
    }

    auto change = [&](int i, int j, int64_t val) {
      if (i < 0 || i >= sz || j < 0 || j >= sz) return;

      int pos = id(i, j);
      int64_t old = c[pos], nxt = old + val;

      bit.add(i, j, nxt * nxt - old * old);
      c[pos] = nxt;
    };

    while (q--) {
      char op;
      int r1, c1, r2, c2;

      cin >> op >> r1 >> c1 >> r2 >> c2;

      if (op == 'U') {
        int64_t x;
        cin >> x;

        change(r1 - 2, c1 - 2, -x);
        change(r2 - 1, c1 - 2, x);
        change(r1 - 2, c2 - 1, x);
        change(r2 - 1, c2 - 1, -x);
      } else {
        if (r1 == r2 || c1 == c2) {
          cout << "YES\n";
        } else {
          int64_t val = bit.query(r1 - 1, c1 - 1, r2 - 2, c2 - 2);
          cout << (!val ? "YES\n" : "NO\n");
        }
      }
    }
  }

  return 0;
}
