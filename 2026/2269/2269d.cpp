/*!
 * author: manhhomienbienthuy
 * created: 2026-09-26T15:16:16+00:00
 * https://codeforces.com/contest/2269/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

const int S = 8;

struct node {
  array<int, S> f;
};

int val[S];

node merge_tree(const node& a, const node& b) {
  node c;
  c.f.fill(INT_MIN);

  for (int x = 0; x < S; x++) {
    for (int y = 0; y < S; y++) {
      int d = x ^ y;
      c.f[d] = max(c.f[d], a.f[x] + b.f[y]);
    }
  }

  return c;
}

node make_node(int a) {
  node r;

  for (int x = 0; x < S; x++) {
    r.f[x] = ((a ^ val[x]) % 3 == 0);
  }

  return r;
}

struct seg_tree {
  int n;
  vector<node> st;

  seg_tree(const vector<int>& a) {
    n = 1;
    while (n < (int)a.size()) n <<= 1;

    st.resize(n << 1);

    for (int i = 0; i < n; i++) {
      if (i < (int)a.size()) {
        st[n + i] = make_node(a[i]);
      } else {
        st[n + i].f.fill(INT_MIN);
        st[n + i].f[0] = 0;
      }
    }

    for (int v = n - 1; v > 0; v--) {
      st[v] = merge_tree(st[v << 1], st[v << 1 | 1]);
    }
  }

  void update(int pos, int x) {
    int v = n + pos;
    st[v] = make_node(x);

    for (v >>= 1; v > 0; v >>= 1) {
      st[v] = merge_tree(st[v << 1], st[v << 1 | 1]);
    }
  }

  int query() { return st[1].f[0]; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int id = 0;

  for (int x = 0; x < 16; x++) {
    if (__builtin_popcount(x) % 2 == 0) {
      val[id++] = x;
    }
  }

  int t;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    seg_tree st(a);

    cout << st.query() << ' ';

    while (q--) {
      int p, x;
      cin >> p >> x;

      a[p - 1] = x;
      st.update(p - 1, x);

      cout << st.query() << ' ';
    }

    cout << '\n';
  }

  return 0;
}
