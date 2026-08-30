/*!
 * author: manhhomienbienthuy
 * created: 2026-08-29T16:29:02+00:00
 * https://codeforces.com/contest/2258/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

struct node {
  int64_t l, r;
  int col;
  bool ok;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<node> seg;
    map<int64_t, int> mp[2];
    priority_queue<pair<int64_t, int>> pq;

    auto add = [&](int64_t l, int64_t r, int col) {
      if (l > r) return;

      int id = (int)seg.size();

      seg.push_back({l, r, col, true});
      mp[col][l] = id;
      pq.push({r - l + 1, id});
    };

    for (int col = 0; col < 2; col++) {
      int cnt = col == 0 ? n : m;

      for (int i = 0; i < cnt; i++) {
        int64_t l, r;
        cin >> l >> r;

        add(l, r, col);
      }
    }

    vector<int64_t> ans;

    auto erase = [&](int col, int64_t ql, int64_t qr) {
      auto it = mp[col].upper_bound(ql);

      if (it != mp[col].begin()) it--;

      vector<pair<int64_t, int64_t>> rem;

      while (it != mp[col].end()) {
        int id = it->second;
        int64_t l = seg[id].l;
        int64_t r = seg[id].r;

        if (l > qr) break;

        if (r < ql) {
          it++;
          continue;
        }

        seg[id].ok = false;
        it = mp[col].erase(it);

        if (l < ql) rem.push_back({l, ql - 1});

        if (qr < r) rem.push_back({qr + 1, r});
      }

      for (auto [l, r] : rem) add(l, r, col);
    };

    while (!pq.empty()) {
      auto [len, id] = pq.top();
      pq.pop();

      if (!seg[id].ok) continue;

      int64_t l = seg[id].l;
      int64_t r = seg[id].r;
      int col = seg[id].col;

      seg[id].ok = false;
      mp[col].erase(l);

      ans.push_back(len);

      erase(col ^ 1, l, r);
    }

    cout << ans.size() << '\n';

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}
