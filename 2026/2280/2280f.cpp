/*!
 * author: manhhomienbienthuy
 * created: 2026-11-09T01:18:00+00:00
 * https://codeforces.com/contest/2280/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int src, const vector<vector<int>>& g) {
  int n = (int)g.size();

  vector<int> dist(n, -1);
  queue<int> q;

  dist[src] = 0;
  q.push(src);

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    for (int to : g[v]) {
      if (dist[to] != -1) continue;

      dist[to] = dist[v] + 1;
      q.push(to);
    }
  }

  return dist;
}

vector<int> bfs_multi(const vector<int>& src, const vector<vector<int>>& g) {
  int n = (int)g.size();

  vector<int> dist(n, -1);
  queue<int> q;

  for (int v : src) {
    dist[v] = 0;
    q.push(v);
  }

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    for (int to : g[v]) {
      if (dist[to] != -1) continue;

      dist[to] = dist[v] + 1;
      q.push(to);
    }
  }

  return dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    int w, x, y, z;
    cin >> w >> x >> y >> z;

    w--;
    x--;
    y--;
    z--;

    vector<vector<int>> g(n);
    bool ac_edge = false;

    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;

      a--;
      b--;

      g[a].push_back(b);
      g[b].push_back(a);

      if ((a == w && b == y) || (a == y && b == w)) ac_edge = true;
    }

    vector<int> dx = bfs(x, g), dz = bfs(z, g);

    int ans = INT_MAX / 4;

    if (w == y) ans = min(ans, dx[z]);

    if (ac_edge) ans = min(ans, dx[y] + 1 + dz[w]);

    vector<vector<int>> src(3);

    for (int p : g[w]) {
      int type = dx[p] - dx[w] + 1;
      src[type].push_back(p);
    }

    for (int type = 0; type <= 2; type++) {
      if (src[type].empty()) continue;

      vector<int> dis3 = bfs_multi(src[type], g);

      for (int p : g[y]) {
        int cur = dx[w] + type;
        cur += 3 * (dis3[p] + 1);
        cur += dz[p];

        ans = min(ans, cur);
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
