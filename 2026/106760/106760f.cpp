/*!
 * author: manhhomienbienthuy
 * created: 2026-10-20T04:25:50+00:00
 * https://codeforces.com/gym/106760/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

struct seg_tree {
  int n;
  int version;

  vector<int64_t> st;
  vector<int> node_version;

  seg_tree(int n) : n(n), version(1), st(4 * n, 0), node_version(4 * n, 0) {}

  int64_t value(int v) const {
    if (node_version[v] != version) {
      return 0;
    }

    return st[v];
  }

  void touch(int v) {
    if (node_version[v] != version) {
      node_version[v] = version;
      st[v] = 0;
    }
  }

  void reset() { version++; }

  void update(int v, int l, int r, int pos, int val) {
    touch(v);

    if (l == r) {
      st[v] = val;
      return;
    }

    int m = (l + r) >> 1;

    if (pos <= m) {
      update(v << 1, l, m, pos, val);
    } else {
      update(v << 1 | 1, m + 1, r, pos, val);
    }

    st[v] = value(v << 1) + value(v << 1 | 1);
  }

  void update(int pos, int val) { update(1, 0, n - 1, pos, val); }

  int64_t query(int v, int l, int r, int ql, int qr) const {
    if (ql > r || qr < l) {
      return 0;
    }

    if (node_version[v] != version) {
      return 0;
    }

    if (ql <= l && r <= qr) {
      return st[v];
    }

    int m = (l + r) >> 1;

    return query(v << 1, l, m, ql, qr) + query(v << 1 | 1, m + 1, r, ql, qr);
  }

  int64_t query(int l, int r) const {
    if (l > r) {
      return 0;
    }

    return query(1, 0, n - 1, l, r);
  }

  int get(int pos) const { return (int)(query(pos, pos)); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;

    seg_tree tree(n);

    vector<int> cnt(n + 1, 0);
    set<int> vals;

    auto add = [&](int val) {
      if (val == 0) return;

      if (cnt[val] == 0) vals.insert(val);

      cnt[val]++;
    };

    auto remove = [&](int val) {
      if (val == 0) return;

      cnt[val]--;

      if (cnt[val] == 0) vals.erase(val);
    };

    while (q--) {
      int ops;
      cin >> ops;

      if (ops == 1) {
        vector<pair<int, int>> entries;

        for (int v : vals) entries.emplace_back(v, cnt[v]);
        for (int v : vals) cnt[v] = 0;

        vals.clear();
        tree.reset();

        for (auto [pos, val] : entries) {
          tree.update(pos - 1, val);
          add(val);
        }
      } else if (ops == 2) {
        int i, x;
        cin >> i >> x;

        i--;

        int old = tree.get(i);

        if (old == x) continue;

        remove(old);
        add(x);

        tree.update(i, x);
      } else {
        int l, r;
        cin >> l >> r;

        l--;
        r--;

        cout << tree.query(l, r) << '\n';
      }
    }
  }

  return 0;
}
