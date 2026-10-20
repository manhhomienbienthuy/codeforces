/*!
 * author: manhhomienbienthuy
 * created: 2026-10-20T04:25:50+00:00
 * https://codeforces.com/gym/106760/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

struct fenwick {
  int n, version;
  vector<int64_t> bit;
  vector<int> node_version;

  fenwick(int n) : n(n), version(1), bit(n + 1, 0), node_version(n + 1, 1) {}

  int64_t value(int i) { return node_version[i] == version ? bit[i] : 0; }

  void touch(int i) {
    if (node_version[i] != version) {
      node_version[i] = version;
      bit[i] = 0;
    }
  }

  void reset() { version++; }

  void add(int i, int64_t v) {
    for (i++; i <= n; i += i & -i) {
      touch(i);
      bit[i] += v;
    }
  }

  int64_t sum(int i) {
    int64_t r = 0;
    for (i++; i > 0; i -= i & -i) r += value(i);
    return r;
  }

  int64_t query(int l, int r) {
    if (l > r) return 0;
    return sum(r) - sum(l - 1);
  }

  int get(int i) { return int(query(i, i)); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;

    fenwick bit(n + 1);

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
        bit.reset();

        for (auto [pos, val] : entries) {
          bit.add(pos, val);
          add(val);
        }
      } else if (ops == 2) {
        int i, x;
        cin >> i >> x;

        int old = bit.get(i);

        if (old == x) continue;

        remove(old);
        add(x);

        bit.add(i, x - old);
      } else {
        int l, r;
        cin >> l >> r;

        cout << bit.query(l, r) << '\n';
      }
    }
  }

  return 0;
}
