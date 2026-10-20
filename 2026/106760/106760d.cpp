/*!
 * author: manhhomienbienthuy
 * created: 2026-10-20T03:28:17+00:00
 * https://codeforces.com/gym/106760/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);

    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      u--;
      v--;

      g[u].push_back(v);
      g[v].push_back(u);
    }

    vector<pair<int, int>> ans;
    vector<int> mark(n, -1);

    for (int u = 0; u < n; u++) {
      mark[u] = u;

      for (int v : g[u]) {
        mark[v] = u;

        for (int p : g[v]) mark[p] = u;
      }

      for (int v = u + 1; v < n; v++) {
        if (mark[v] == u) ans.emplace_back(u + 1, v + 1);
      }
    }

    cout << ans.size() << '\n';
    for (auto [u, v] : ans) cout << u << ' ' << v << '\n';
  }

  return 0;
}
