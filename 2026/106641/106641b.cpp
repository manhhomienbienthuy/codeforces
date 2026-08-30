/*!
 * author: manhhomienbienthuy
 * created: 2026-08-21T05:36:23+00:00
 * https://codeforces.com/gym/106641/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

struct lazy_seg {
  int n;
  vector<int64_t> mx, lazy;

  lazy_seg(int n) : n(n), mx(4 * n), lazy(4 * n) {}

  void apply(int v, int64_t val) {
    mx[v] += val;
    lazy[v] += val;
  }

  void push(int v) {
    if (!lazy[v]) return;

    apply(v << 1, lazy[v]);
    apply(v << 1 | 1, lazy[v]);
    lazy[v] = 0;
  }

  void add(int v, int l, int r, int ql, int qr, int64_t val) {
    if (ql > r || qr < l) return;

    if (ql <= l && r <= qr) {
      apply(v, val);
      return;
    }

    push(v);

    int m = (l + r) >> 1;
    add(v << 1, l, m, ql, qr, val);
    add(v << 1 | 1, m + 1, r, ql, qr, val);
    mx[v] = mx[v << 1] + mx[v << 1 | 1];
  }

  void add(int l, int r, int val) {
    if (l > r) {
      return;
    }

    add(1, 0, n - 1, l, r, val);
  }

  int64_t query(int v, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;

    if (ql <= l && r <= qr) return mx[v];

    push(v);

    int m = (l + r) >> 1;
    return query(v << 1, l, m, ql, qr) + query(v << 1 | 1, m + 1, r, ql, qr);
  }

  int64_t query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q, id = 0;
  cin >> n >> q;

  vector<int> read(n + 1);
  lazy_seg seg(q + 1);

  while (q--) {
    int ops;
    cin >> ops;

    switch (ops) {
      case 1:
        id++;
        break;
      case 2:
        int f;
        cin >> f;
        seg.add(read[f] + 1, id, 1);
        read[f] = id;
        break;
      case 3:
        int s;
        cin >> s;
        cout << seg.query(s, s) << '\n';
        break;
    }
  }

  return 0;
}
