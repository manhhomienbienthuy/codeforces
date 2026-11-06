/*!
 * author: manhhomienbienthuy
 * created: 2026-11-04T15:15:07+00:00
 * https://codeforces.com/contest/2283/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

struct lca_tree {
  int n, lg;
  vector<int> dep;
  vector<vector<int>> up, g;

  lca_tree(int n) : n(n) {
    lg = 1;

    while ((1 << lg) <= n) lg++;

    dep.assign(n, 0);
    up.assign(lg, vector<int>(n));
    g.assign(n, vector<int>());
  }

  void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }

  void build(int root = 0) {
    vector<int> stk = {root};
    up[0][root] = root;

    vector<bool> vis(n, false);
    vis[root] = true;

    while (!stk.empty()) {
      int v = stk.back();
      stk.pop_back();

      for (int k = 1; k < lg; k++) up[k][v] = up[k - 1][up[k - 1][v]];

      for (int to : g[v]) {
        if (!vis[to]) {
          vis[to] = true;
          dep[to] = dep[v] + 1;
          up[0][to] = v;
          stk.push_back(to);
        }
      }
    }
  }

  int kth(int v, int k) {
    for (int i = 0; i < lg; i++)
      if (k >> i & 1) v = up[i][v];
    return v;
  }

  int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);

    a = kth(a, dep[a] - dep[b]);

    if (a == b) return a;

    for (int i = lg - 1; i >= 0; i--)
      if (up[i][a] != up[i][b]) {
        a = up[i][a];
        b = up[i][b];
      }

    return up[0][a];
  }

  int dist(int a, int b) {
    int c = lca(a, b);
    return dep[a] + dep[b] - 2 * dep[c];
  }

  bool on_path(int u, int v, int x) {
    return dist(u, v) == dist(u, x) + dist(x, v);
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

    if (!(n & 1)) {
      for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
      }

      cout << n + 1 << '\n';
      continue;
    }

    lca_tree tree(n);

    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;

      u--;
      v--;

      tree.add_edge(u, v);
    }

    tree.build();

    vector<pair<int, int>> cand = {
        {n, n - 1},
        {n + 1, n / 2},
        {n + 2, 0},
    };

    int ans = n;

    for (auto [k, x] : cand) {
      bool gray = false;

      for (int u = 0; !gray && u < n; u++) {
        int v = k - u - 2;

        if (v < 0 || v >= n || u >= v) continue;

        gray = tree.on_path(u, v, x);
      }

      if (gray) {
        ans = k;
        break;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
