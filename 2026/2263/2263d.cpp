/*!
 * author: manhhomienbienthuy
 * created: 2026-09-12T16:09:48+00:00
 * https://codeforces.com/contest/2263/problem/D
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

    fenwick bit(n);
    set<int> brk;

    vector<int> ans(n);

    for (int k = n - 1; k >= 0; k--) {
      int pos = p[k];

      bit.add(pos, a[pos]);

      auto it = brk.upper_bound(pos);

      int prv = -1;

      if (it != brk.begin()) {
        prv = *prev(it);
      }

      if (prv == -1 || bit.query(prv, pos - 1) < a[pos]) {
        brk.insert(pos);
        prv = pos;
      }

      while (true) {
        auto nxt_it = brk.upper_bound(prv);

        if (nxt_it == brk.end()) break;

        int nxt = *nxt_it;

        if (bit.query(prv, nxt - 1) < a[nxt]) break;

        brk.erase(nxt_it);
      }

      ans[k] = (int)brk.size() - 1;
    }

    for (int x : ans) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}
