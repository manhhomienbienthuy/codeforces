/*!
 * author: manhhomienbienthuy
 * created: 2026-10-26T15:33:29+00:00
 * https://codeforces.com/contest/2272/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int find_hub(const vector<vector<int>>& g, int n) {
  vector<int> parent(n, -1), ord;

  deque<int> dq;
  dq.push_back(0);
  parent[0] = 0;

  while (!dq.empty()) {
    int v = dq.front();
    dq.pop_front();

    ord.push_back(v);

    for (int u : g[v]) {
      if (u == parent[v]) continue;

      parent[u] = v;
      dq.push_back(u);
    }
  }

  vector<int> dp0(n, 0), dp1(n, 1);

  for (int i = n - 1; i >= 0; i--) {
    int v = ord[i];

    for (int u : g[v]) {
      if (parent[u] != v) continue;

      dp0[v] += max(dp0[u], dp1[u]);
      dp1[v] += dp0[u];
    }
  }

  if (dp0[0] >= dp1[0]) return 0;

  return g[0][0];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int k;
    cin >> k;

    int hub_t = -1, hub_v = -1;

    for (int i = 0; i < k; i++) {
      int n;
      cin >> n;

      vector<vector<int>> g(n);

      for (int j = 0; j < n - 1; j++) {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].push_back(v);
        g[v].push_back(u);
      }

      if (hub_t == -1 && n > 1) {
        hub_t = i;
        hub_v = find_hub(g, n);
      }
    }

    if (hub_t == -1) {
      hub_t = 0;
      hub_v = 0;
    }

    for (int i = 0; i < k; i++) {
      if (i == hub_t) continue;

      cout << hub_t + 1 << ' ' << hub_v + 1 << ' ' << i + 1 << ' ' << 1 << '\n';
    }
  }

  return 0;
}
