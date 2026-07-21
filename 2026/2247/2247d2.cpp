/*!
 * author: manhhomienbienthuy
 * created: 2026-07-20T01:11:11+00:00
 * https://codeforces.com/contest/2247/problem/D2
 */

#include <bits/stdc++.h>
using namespace std;

struct info {
  int mn, mx, ans;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;

    int sz = n | n >> 1;
    sz |= sz >> 2;
    sz |= sz >> 4;
    sz |= sz >> 8;
    sz |= sz >> 16;
    sz += 1;

    vector<info> st(sz << 1);

    auto pull = [&](int p, int len) {
      auto& l = st[p << 1];
      auto& r = st[p << 1 | 1];

      st[p].mn = min(l.mn, r.mn);
      st[p].mx = max(l.mx, r.mx);

      if (l.mx <= r.mn)
        st[p].ans = max(l.ans, r.ans);
      else
        st[p].ans = max({l.ans, r.ans, len / 2});
    };

    for (int i = 0; i < sz; i++) {
      int v = INT_MAX;
      if (i < n) cin >> v;

      st[sz + i] = {v, v, 0};
    }

    for (int p = sz - 1; p >= 1; p--) {
      int len = sz;
      int x = p;
      while (x > 1) {
        len >>= 1;
        x >>= 1;
      }
      pull(p, len);
    }

    auto update = [&](int idx, int val) {
      int p = sz + idx;
      st[p] = {val, val, 0};

      int len = 1;

      for (p >>= 1; p; p >>= 1) {
        len <<= 1;
        pull(p, len);
      }
    };

    cout << st[1].ans << '\n';

    while (q--) {
      int i, x;
      cin >> i >> x;

      update(i, x);
      cout << st[1].ans << '\n';
    }
  }

  return 0;
}
