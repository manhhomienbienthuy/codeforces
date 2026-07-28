/*!
 * author: manhhomienbienthuy
 * created: 2026-07-27T06:28:14+00:00
 * https://codeforces.com/contest/2250/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

struct seg_tree {
  int n;
  vector<int> mx, lazy;
  vector<bool> dead;

  seg_tree(int n) : n(n), mx(4 * n, 0), lazy(4 * n, 0), dead(4 * n, false) {}

  void push(int v) {
    if (lazy[v]) {
      for (int c : {2 * v, 2 * v + 1}) {
        if (!dead[c]) {
          mx[c] += lazy[v];
          lazy[c] += lazy[v];
        }
      }

      lazy[v] = 0;
    }
  }

  void update(int v, int l, int r, int ql, int qr, int val) {
    if (ql > r || qr < l || dead[v]) return;

    if (ql <= l && r <= qr) {
      mx[v] += val;
      lazy[v] += val;
      return;
    }

    push(v);
    int m = (l + r) / 2;
    update(2 * v, l, m, ql, qr, val);
    update(2 * v + 1, m + 1, r, ql, qr, val);
    mx[v] = max(mx[2 * v], mx[2 * v + 1]);
  }

  void kill(int v, int l, int r, int ql, int qr, int thr, int& cnt) {
    if (ql > r || qr < l || dead[v] || mx[v] < thr) return;

    if (l == r) {
      dead[v] = true;
      mx[v] = 0;
      lazy[v] = 0;
      cnt++;
      return;
    }

    push(v);
    int m = (l + r) / 2;
    kill(2 * v, l, m, ql, qr, thr, cnt);
    kill(2 * v + 1, m + 1, r, ql, qr, thr, cnt);

    if (dead[2 * v] && dead[2 * v + 1]) dead[v] = true;

    mx[v] =
        max(dead[2 * v] ? 0 : mx[2 * v], dead[2 * v + 1] ? 0 : mx[2 * v + 1]);
  }

  void range_add(int l, int r, int val) { update(1, 0, n - 1, l, r, val); }

  void kill_ge3(int l, int r, int& cnt) { kill(1, 0, n - 1, l, r, 3, cnt); }
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

    seg_tree st(n);
    int bad = 0;

    for (int r = 0; r < 2 * n - 1; r++) {
      int x = p[r % n];

      int left = max(0, r - n + 1);
      int right = min(r, n - 1);

      st.range_add(left, right, 1);

      if (x > 1 && last[x - 1] >= left)
        st.range_add(left, min(right, last[x - 1]), -1);

      if (x < n && last[x + 1] >= left)
        st.range_add(left, min(right, last[x + 1]), -1);

      st.kill_ge3(left, right, bad);

      last[x] = r;
    }

    cout << n - bad << '\n';
  }

  return 0;
}
