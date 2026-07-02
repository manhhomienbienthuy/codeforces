/*!
 * author: manhhomienbienthuy
 * created: 2026-07-01T08:06:30+00:00
 * https://codeforces.com/contest/2241/problem/E
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

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    vector<int> parent(n + 1, 0);
    parent[1] = -1;
    vector<int> sz(n + 1, 1);
    vector<int> q;

    stack<int> st;
    st.push(1);
    while (!st.empty()) {
      int u = st.top();
      st.pop();
      q.push_back(u);

      for (int v : g[u]) {
        if (v == parent[u]) continue;
        parent[v] = u;
        st.push(v);
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      int u = q[i];
      for (int v : g[u]) {
        if (v == parent[u]) continue;
        sz[u] += sz[v];
      }
    }

    int64_t ans = 0, t_sz = n - 1;

    for (int u = 1; u <= n; u++) {
      int r = (int)sqrt(a[u]);
      if (r * r != a[u]) continue;

      int64_t s2 = 0, s3 = 0;

      for (int v : g[u]) {
        if (v == parent[u]) continue;
        int64_t s = sz[v];
        s2 += s * s;
        s3 += s * s * s;
      }

      int64_t up = n - sz[u];
      if (up > 0) {
        s2 += up * up;
        s3 += up * up * up;
      }

      int64_t c1 = (t_sz * t_sz - s2) / 2,
              c2 = (t_sz * t_sz * t_sz - 3 * t_sz * s2 + 2 * s3) / 6;
      int64_t cnt = c1 + c2;

      ans += cnt;
    }

    cout << ans << '\n';
  }

  return 0;
}
