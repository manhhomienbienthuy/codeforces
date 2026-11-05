/*!
 * author: manhhomienbienthuy
 * created: 2026-11-04T15:15:07+00:00
 * https://codeforces.com/contest/2283/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;

      u--;
      v--;

      g[u].push_back(v);
      g[v].push_back(u);
    }

    if (!(n & 1)) {
      cout << n + 1 << '\n';
      continue;
    }

    int q;
    for (q = 1; (1 << q) <= n; q++);

    vector<int> depth(n);
    vector<vector<int>> up(q, vector<int>(n));

    stack<int> st;
    st.push(0);

    while (!st.empty()) {
      int v = st.top();
      st.pop();

      for (int j = 1; j < q; j++) {
        up[j][v] = up[j - 1][up[j - 1][v]];
      }

      for (int u : g[v]) {
        if (u == up[0][v]) continue;

        up[0][u] = v;
        depth[u] = depth[v] + 1;
        st.push(u);
      }
    }

    auto lca = [&](int u, int v) {
      if (depth[u] < depth[v]) swap(u, v);

      int k = depth[u] - depth[v];

      for (int j = 0; j < q; j++)
        if ((k >> j) & 1) u = up[j][u];

      if (u == v) return u;

      for (int j = q - 1; j >= 0; j--) {
        if (up[j][u] != up[j][v]) {
          u = up[j][u];
          v = up[j][v];
        }
      }

      return up[0][u];
    };

    auto dist = [&](int u, int v) {
      int w = lca(u, v);
      return depth[u] + depth[v] - 2 * depth[w];
    };

    vector<pair<int, int>> cand = {
        {n, n - 1},
        {n + 1, n / 2},
        {n + 2, 0},
    };

    int ans = n;

    for (auto [k, x] : cand) {
      bool gray = false;

      for (int u = 0; u < n && !gray; u++) {
        int v = k - u - 2;

        if (v < 0 || v >= n || u >= v) continue;

        gray = gray || (dist(u, v) == dist(u, x) + dist(x, v));
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
