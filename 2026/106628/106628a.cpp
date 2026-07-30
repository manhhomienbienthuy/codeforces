/*!
 * author: manhhomienbienthuy
 * created: 2026-07-29T08:34:58+00:00
 * https://codeforces.com/gym/106628/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

struct fenwick {
  int n;
  vector<int64_t> bit;

  fenwick(int n) : n(n), bit(n + 1, 0) {}

  void add(int i, int64_t v) {
    for (i++; i <= n; i += i & -i) bit[i] += v;
  }

  int64_t sum(int i) {
    int64_t r = 0;
    for (i++; i > 0; i -= i & -i) r += bit[i];
    return r;
  }

  int64_t query(int l, int r) {
    if (l > r) return 0;
    return sum(r) - sum(l - 1);
  }
};

struct query {
  int l, r, id;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int> pref(n, -1), suf(n, n);

    stack<int> st;

    for (int i = 0; i < n; i++) {
      while (!st.empty() && a[st.top()] <= a[i]) {
        suf[st.top()] = i;
        st.pop();
      }

      if (!st.empty()) pref[i] = st.top();
      st.push(i);
    }

    vector<pair<int, int>> pts;

    for (int i = 1; i + 1 < n; i++) {
      if (pref[i] != -1 && suf[i] != n) pts.push_back({suf[i], pref[i]});
    }

    sort(pts.begin(), pts.end());

    vector<query> qs(q);

    for (int i = 0; i < q; i++) {
      cin >> qs[i].l >> qs[i].r;
      qs[i].l--;
      qs[i].r--;
      qs[i].id = i;
    }

    sort(qs.begin(), qs.end(),
         [&](const query& a, const query& b) { return a.r < b.r; });

    fenwick bit(n);

    vector<int> ans(q);

    int p = 0;

    for (auto [l, r, id] : qs) {
      while (p < (int)pts.size() && pts[p].first <= r) {
        bit.add(pts[p].second, 1);
        p++;
      }

      int bad = bit.query(l, n - 1);

      ans[id] = (r - l + 1) - bad;
    }

    for (int x : ans) {
      cout << x << '\n';
    }
  }

  return 0;
}
