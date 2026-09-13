/*!
 * author: manhhomienbienthuy
 * created: 2026-09-12T16:09:48+00:00
 * https://codeforces.com/contest/2263/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

struct node {
  int64_t sum = 0;
  int64_t need = 0;
};

struct seg_tree {
  int n;
  vector<node> st;

  seg_tree(int n) : n(n), st(4 * n) {}

  node merge_node(const node& l, const node& r) {
    node res;

    res.sum = l.sum + r.sum;
    res.need = max(l.need, r.need - l.sum);

    return res;
  }

  void update(int v, int l, int r, int pos, int64_t val) {
    if (l == r) {
      st[v] = {val, val};
      return;
    }

    int m = (l + r) >> 1;

    if (pos <= m) {
      update(v << 1, l, m, pos, val);
    } else {
      update(v << 1 | 1, m + 1, r, pos, val);
    }

    st[v] = merge_node(st[v << 1], st[v << 1 | 1]);
  }

  pair<int, int64_t> calc(int v, int l, int r, int64_t skill) {
    if (skill >= st[v].need) {
      return {0, skill + st[v].sum};
    }

    if (l == r) {
      return {1, st[v].sum};
    }

    int m = (l + r) >> 1;

    auto [cnt_l, skill_l] = calc(v << 1, l, m, skill);

    auto [cnt_r, skill_r] = calc(v << 1 | 1, m + 1, r, skill_l);

    return {cnt_l + cnt_r, skill_r};
  }

  void update(int pos, int64_t val) { update(1, 0, n - 1, pos, val); }

  int calc() {
    auto [cnt, skill] = calc(1, 0, n - 1, 0);

    return max(0, cnt - 1);
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

    vector<int64_t> a(n);

    for (int64_t& x : a) cin >> x;

    vector<int> p(n);

    for (int& x : p) {
      cin >> x;
      x--;
    }

    seg_tree st(n);
    vector<int> ans(n);

    for (int k = n - 1; k >= 0; k--) {
      int pos = p[k];

      st.update(pos, a[pos]);
      ans[k] = st.calc();
    }

    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
  }

  return 0;
}
