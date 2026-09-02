/*!
 * author: manhhomienbienthuy
 * created: 2026-09-02T01:12:40+00:00
 * https://codeforces.com/contest/2258/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

struct lazy_seg {
  int n;
  vector<int64_t> mn, lazy;

  lazy_seg(int n) : n(n), mn(4 * n), lazy(4 * n) { build(1, 0, n - 1); }

  void build(int v, int l, int r) {
    if (l == r) {
      mn[v] = l;
      return;
    }

    int m = (l + r) >> 1;

    build(v << 1, l, m);
    build(v << 1 | 1, m + 1, r);

    mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
  }

  void apply(int v, int64_t val) {
    mn[v] = max(mn[v], val);
    lazy[v] = max(lazy[v], val);
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
    mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
  }

  void add(int l, int r, int val) {
    if (l > r) {
      return;
    }

    add(1, 0, n - 1, l, r, val);
  }

  int64_t query(int v, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return n;

    if (ql <= l && r <= qr) return mn[v];

    push(v);

    int m = (l + r) >> 1;
    return min(query(v << 1, l, m, ql, qr),
               query(v << 1 | 1, m + 1, r, ql, qr));
  }

  int64_t query(int l, int r) { return query(1, 0, n - 1, l, r); }
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

    int lim = 2 * n + 2;

    vector<int> spf(lim + 1);

    for (int i = 2; i <= lim; i++) {
      if (!spf[i]) {
        spf[i] = i;

        for (int64_t j = 1ll * i * i; j <= lim; j += i) {
          if (!spf[j]) spf[j] = i;
        }
      }
    }

    vector<vector<int>> pos(lim * +1);

    for (int i = 0; i < n; i++) {
      int x = a[i];

      while (x > 1) {
        int p = spf[x], pw = p;

        while (!(x % p)) {
          pos[pw].push_back(i);
          x /= p;
          pw *= p;
        }
      }
    }

    vector<int> cand;

    for (int p = 2; p <= lim; p++) {
      if (spf[p] != p) continue;

      for (int64_t d = p; d <= lim; d *= p) cand.push_back((int)d);
    }

    sort(cand.begin(), cand.end());

    lazy_seg st(n);

    vector<int> ans;

    for (int d : cand) {
      bool ok = false;
      int prv = -1;

      for (int r : pos[d]) {
        int l = prv + 1;

        ok = ok || (st.query(l, r) < r);

        st.add(l, r, r);

        prv = r;
      }

      int l = prv + 1;

      if (l < n) {
        ok = ok || (st.query(l, n - 1) < n);

        st.add(l, n - 1, n);
      }

      if (ok) ans.push_back(d);

      if (st.mn[1] == n) break;
    }

    cout << ans.size() << '\n';

    for (int x : ans) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}
