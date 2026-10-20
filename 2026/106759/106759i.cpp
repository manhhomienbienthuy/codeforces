/*!
 * author: manhhomienbienthuy
 * created: 2026-10-20T01:25:10+00:00
 * https://codeforces.com/gym/106759/problem/I
 */

#include <bits/stdc++.h>
using namespace std;

struct seg_tree {
  int n;
  vector<int> st;

  seg_tree(int n) : n(n), st(4 * n, 0) {}

  void update(int v, int l, int r, int pos, int val) {
    if (l == r) {
      st[v] = val;
      return;
    }

    int m = (l + r) >> 1;
    if (pos <= m)
      update(v << 1, l, m, pos, val);
    else
      update(v << 1 | 1, m + 1, r, pos, val);

    st[v] = max(st[v << 1], st[v << 1 | 1]);
  }

  void update(int p, int val) { update(1, 0, n - 1, p, val); }

  int query(int v, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return INT_MIN;

    if (ql <= l && r <= qr) return st[v];

    int m = (l + r) >> 1;
    return max(query(v << 1, l, m, ql, qr),
               query(v << 1 | 1, m + 1, r, ql, qr));
  }

  int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> h(n);
    for (int& x : h) cin >> x;

    seg_tree dp(n + 1);
    int cur = -1;

    for (int i = 0; i < n; ++i) {
      int cand = dp.query(0, h[i] - 1) + 1, nxt = -1;

      if (i + 1 < n) {
        nxt = dp.query(0, h[i] - 1) + 1;

        if (h[i + 1] < h[i]) {
          nxt = max(nxt, 2 + dp.query(0, h[i + 1] - 1));
        }
      }

      dp.update(h[i], cand);

      if (cur != -1) dp.update(h[i - 1], cur);

      cur = nxt;
    }

    cout << dp.query(0, n) << '\n';
  }

  return 0;
}
