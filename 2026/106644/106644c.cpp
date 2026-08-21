/*!
 * author: manhhomienbienthuy
 * created: 2026-08-16T14:04:59+00:00
 * https://codeforces.com/gym/106644/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

struct dsu {
  vector<int> p;

  dsu(int n) : p(n) { iota(p.begin(), p.end(), 0); }

  int find(int v) {
    while (p[v] != v) v = p[v] = p[p[v]];
    return v;
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;

    p[b] = a;

    return true;
  }
};

struct pair_hash {
  size_t operator()(const pair<int, int>& p) const {
    return (uint64_t)p.first << 32 | (uint32_t)p.second;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n + 1);
  dsu uf(n + 1);

  while (m--) {
    int u, v;
    cin >> u >> v;

    g[u].push_back(v);
    g[v].push_back(u);

    uf.unite(u, v);
  }

  vector<int> white(n + 1, -1), mark(n + 1, 0);

  set<int> rem;
  for (int v = 1; v <= n; v++) rem.insert(v);

  int cid = 0, cc = 0;

  for (int s = 1; s <= n; s++) {
    if (white[s] != -1) continue;

    cid++;

    queue<int> q;
    q.push(s);

    white[s] = cid;
    rem.erase(s);

    while (!q.empty()) {
      int v = q.front();
      q.pop();

      cc++;

      for (int to : g[v]) mark[to] = cc;

      for (auto it = rem.begin(); it != rem.end();) {
        int u = *it;

        if (mark[u] != cc) {
          white[u] = cid;
          q.push(u);
          it = rem.erase(it);
        } else {
          it++;
        }
      }
    }
  }

  unordered_map<pair<int, int>, int64_t, pair_hash> cnt;

  for (int v = 1; v <= n; v++) cnt[{uf.find(v), white[v]}]++;

  int64_t ans = 0;

  for (auto& [key, c] : cnt) ans += c * (c - 1) / 2;

  cout << ans << '\n';

  return 0;
}
