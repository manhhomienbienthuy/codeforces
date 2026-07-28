/*!
 * author: manhhomienbienthuy
 * created: 2026-07-27T06:28:14+00:00
 * https://codeforces.com/contest/2250/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

struct lazy_seg {
  int n;
  vector<int> mx, lazy;
  vector<bool> dead;

  lazy_seg(int n_) : n(n_), mx(4 * n, 0), lazy(4 * n, 0), dead(4 * n, false) {}

  void apply(int v, int val) {
    mx[v] += val;
    lazy[v] += val;
  }

  void push(int v) {
    if (!lazy[v]) {
      return;
    }

    for (int c : {v << 1, v << 1 | 1}) {
      if (!dead[c]) {
        apply(c, lazy[v]);
      }
    }

    lazy[v] = 0;
  }

  void pull(int v) {
    mx[v] = max(dead[v << 1] ? 0 : mx[v << 1],
                dead[v << 1 | 1] ? 0 : mx[v << 1 | 1]);

    dead[v] = dead[v << 1] && dead[v << 1 | 1];
  }

  void add(int v, int l, int r, int ql, int qr, int val) {
    if (ql > r || qr < l || dead[v]) {
      return;
    }

    if (ql <= l && r <= qr) {
      apply(v, val);
      return;
    }

    push(v);

    int m = (l + r) >> 1;

    add(v << 1, l, m, ql, qr, val);
    add(v << 1 | 1, m + 1, r, ql, qr, val);

    pull(v);
  }

  void add(int l, int r, int val) {
    if (l > r) {
      return;
    }

    add(1, 0, n - 1, l, r, val);
  }

  void kill(int v, int l, int r, int ql, int qr, int thr, int& bad) {
    if (ql > r || qr < l || dead[v] || mx[v] < thr) {
      return;
    }

    if (l == r) {
      dead[v] = 1;
      mx[v] = 0;
      lazy[v] = 0;
      bad++;
      return;
    }

    push(v);

    int m = (l + r) >> 1;

    kill(v << 1, l, m, ql, qr, thr, bad);
    kill(v << 1 | 1, m + 1, r, ql, qr, thr, bad);

    pull(v);
  }

  void kill_ge(int l, int r, int thr, int& bad) {
    kill(1, 0, n - 1, l, r, thr, bad);
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

    vector<int> p(n);
    for (int& x : p) cin >> x;

    vector<int> last(n + 1, -1);

    lazy_seg st(n);
    int bad = 0;

    for (int r = 0; r < 2 * n - 1; r++) {
      int x = p[r % n];

      int left = max(0, r - n + 1);
      int right = min(r, n - 1);

      st.add(left, right, 1);

      if (x > 1 && last[x - 1] >= left)
        st.add(left, min(right, last[x - 1]), -1);

      if (x < n && last[x + 1] >= left)
        st.add(left, min(right, last[x + 1]), -1);

      st.kill_ge(left, right, 3, bad);

      last[x] = r;
    }

    cout << n - bad << '\n';
  }

  return 0;
}
