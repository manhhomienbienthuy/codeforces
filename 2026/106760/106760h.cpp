/*!
 * author: manhhomienbienthuy
 * created: 2026-10-21T05:32:08+00:00
 * https://codeforces.com/gym/106760/problem/H
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  string s, t;

  cin >> n >> m >> s >> t;

  vector<vector<int>> g(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    u--;
    v--;

    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> need(n), parent(n, -2), order, root;

  for (int i = 0; i < n; i++) need[i] = (s[i] - '0') ^ (t[i] - '0');

  for (int i = 0; i < n; ++i) {
    if (parent[i] != -2) continue;

    root.push_back(i);
    parent[i] = -1;

    stack<int> st;
    st.push(i);

    while (!st.empty()) {
      int v = st.top();
      st.pop();

      order.push_back(v);

      for (int u : g[v]) {
        if (u == parent[v]) continue;
        if (parent[u] != -2) continue;

        parent[u] = v;
        st.push(u);
      }
    }
  }

  vector<array<array<int64_t, 2>, 2>> dp(n);

  for (int i = n - 1; i >= 0; i--) {
    int p = order[i];

    for (int v = 0; v <= 1; ++v) {
      array<int64_t, 2> ways = {1, 0};

      for (int child : g[p]) {
        if (parent[child] != p) continue;

        array<int64_t, 2> nways = {0, 0};

        for (int cur = 0; cur <= 1; cur++) {
          for (int u = 0; u <= 1; u++) {
            int nxt = cur ^ u;

            nways[nxt] = (nways[nxt] + ways[cur] * dp[child][u][v] % MOD) % MOD;
          }
        }

        ways = nways;
      }

      for (int u = 0; u <= 1; u++) {
        int x = need[p] ^ u;
        dp[p][v][u] = ways[x];
      }
    }
  }

  int64_t ans = 1;

  for (int v : root) {
    int64_t ways = (dp[v][0][0] + dp[v][1][0]) % MOD;
    ans = ans * ways % MOD;
  }

  cout << ans << '\n';

  return 0;
}
