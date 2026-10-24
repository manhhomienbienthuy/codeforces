/*!
 * author: manhhomienbienthuy
 * created: 2026-10-24T11:26:58+00:00
 * https://codeforces.com/contest/2277/problem/C
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

    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;

      x--;
      y--;

      g[x].push_back(y);
      g[y].push_back(x);
    }

    vector<int> v(m);
    for (int& x : v) {
      cin >> x;
      x--;
    }

    vector<int> depth(n), root(n, -1), parent(n, -1);
    stack<int> st;

    for (int x : g[0]) {
      parent[x] = 0;
      depth[x] = 1;
      root[x] = x;
      st.push(x);
    }

    while (!st.empty()) {
      int y = st.top();
      st.pop();

      for (int x : g[y]) {
        if (x == parent[y]) continue;

        parent[x] = y;
        depth[x] = depth[y] + 1;
        root[x] = root[y];

        st.push(x);
      }
    }

    vector<int> dist(n, -1);

    dist[n - 1] = 0;
    st.push(n - 1);

    while (!st.empty()) {
      int y = st.top();
      st.pop();

      for (int x : g[y]) {
        if (dist[x] != -1) continue;

        dist[x] = dist[y] + 1;
        st.push(x);
      }
    }

    int ans = depth[n - 1];

    for (int x : v) {
      if (root[x] == root[n - 1]) ans = max(ans, dist[x] + 1);
    }

    cout << ans << '\n';
  }

  return 0;
}
