/*!
 * author: manhhomienbienthuy
 * created: 2026-10-10T16:34:53+00:00
 * https://codeforces.com/contest/2271/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

struct min_seg {
  int n;
  vector<int> mn, lazy;

  min_seg(const vector<int>& a) : n((int)a.size()), mn(4 * n), lazy(4 * n) {
    build(1, 0, n - 1, a);
  }

  void build(int v, int l, int r, const vector<int>& a) {
    if (l == r) {
      mn[v] = a[l];
      return;
    }

    int m = (l + r) >> 1;

    build(v << 1, l, m, a);
    build(v << 1 | 1, m + 1, r, a);

    mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
  }

  void apply(int v, int x) {
    mn[v] += x;
    lazy[v] += x;
  }

  void push(int v) {
    if (!lazy[v]) return;

    apply(v << 1, lazy[v]);
    apply(v << 1 | 1, lazy[v]);

    lazy[v] = 0;
  }

  void add(int v, int l, int r, int ql, int qr, int x) {
    if (ql > r || qr < l) return;

    if (ql <= l && r <= qr) {
      apply(v, x);
      return;
    }

    push(v);

    int m = (l + r) >> 1;

    add(v << 1, l, m, ql, qr, x);
    add(v << 1 | 1, m + 1, r, ql, qr, x);

    mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
  }

  void add(int l, int r, int x) {
    if (l <= r) add(1, 0, n - 1, l, r, x);
  }

  int all_min() { return mn[1]; }
};

struct max_seg {
  int n;
  vector<int> mx;

  max_seg(const vector<int>& a) : n((int)a.size()), mx(4 * n) {
    build(1, 0, n - 1, a);
  }

  void build(int v, int l, int r, const vector<int>& a) {
    if (l == r) {
      mx[v] = a[l];
      return;
    }

    int m = (l + r) >> 1;

    build(v << 1, l, m, a);
    build(v << 1 | 1, m + 1, r, a);

    mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
  }

  int find_r(int v, int l, int r, int qr, int x) const {
    if (l > qr || mx[v] < x) return -1;

    if (l == r) return l;

    int m = (l + r) >> 1;

    int res = find_r(v << 1 | 1, m + 1, r, qr, x);

    if (res != -1) return res;

    return find_r(v << 1, l, m, qr, x);
  }

  int find_r(int qr, int x) {
    if (qr < 0) return -1;

    return find_r(1, 0, n - 1, qr, x);
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

    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int> pre(n, -1), stk;

    vector<pair<int, int>> pairs;
    vector<vector<int>> inc(n);

    for (int i = 0; i < n; i++) {
      while (!stk.empty() && a[stk.back()] < a[i]) stk.pop_back();

      if (!stk.empty()) {
        pre[i] = stk.back();

        if (a[stk.back()] == a[i]) {
          int id = (int)pairs.size();

          pairs.push_back({stk.back(), i});
          inc[stk.back()].push_back(id);
          inc[i].push_back(id);
        }
      }

      stk.push_back(i);
    }

    vector<int> dif(n + 1), cover(n);

    for (auto [l, r] : pairs) {
      dif[l]++;
      dif[r + 1]--;
    }

    int cur = 0, l = -1, r = -1;

    for (int i = 0; i < n; i++) {
      cur += dif[i];
      cover[i] = cur;

      if (cover[i] == 0) {
        if (l == -1) l = i;
        r = i;
      }
    }

    if (l == -1) {
      cout << 0 << '\n';
      continue;
    }

    bool ok = false;
    int id = -1, val = -1, mx = -1;

    for (int p = l + 1; p < n; p++) {
      if (p >= r && a[p] > mx) {
        ok = true;
        id = l;
        val = a[p];
        break;
      }

      mx = max(mx, a[p]);
    }

    if (!ok) {
      mx = -1;

      for (int p = r - 1; p >= 0; p--) {
        if (p <= l && a[p] > mx) {
          ok = true;
          id = r;
          val = a[p];
          break;
        }

        mx = max(mx, a[p]);
      }
    }

    if (!ok) {
      min_seg cov_st(cover);
      max_seg val_st(a);

      for (int r = 0; r < n && !ok; r++) {
        int j = pre[r];

        if (j == -1 || a[j] == a[r]) continue;

        int l = val_st.find_r(j - 1, a[r]);

        if (l == -1 || a[l] != a[r]) continue;

        if (l > l || r < r) continue;

        for (int x : inc[j]) {
          auto [ql, qr] = pairs[x];
          cov_st.add(ql, qr, -1);
        }

        cov_st.add(l, r, 1);

        if (cov_st.all_min() > 0) {
          ok = true;
          id = j;
          val = a[r];
        }

        cov_st.add(l, r, -1);

        for (int x : inc[j]) {
          auto [ql, qr] = pairs[x];
          cov_st.add(ql, qr, 1);
        }
      }
    }

    if (ok) {
      cout << 1 << '\n';
      cout << id + 1 << ' ' << val << '\n';
    } else {
      cout << 2 << '\n';
      cout << 1 << ' ' << 1000000000 << '\n';
      cout << n << ' ' << 1000000000 << '\n';
    }
  }

  return 0;
}
