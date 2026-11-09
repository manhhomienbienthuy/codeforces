/*!
 * author: manhhomienbienthuy
 * created: 2026-11-09T01:18:00+00:00
 * https://codeforces.com/contest/2280/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

struct fast_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t r =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + r);
  }
};

uint64_t key(int a, int b) { return (uint64_t)(uint32_t)a << 32 | (uint32_t)b; }

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
    vector<int> sa(2 * m), sb(2 * m);

    unordered_map<uint64_t, int, fast_hash> id;
    id.max_load_factor(0.7f);
    id.reserve(2 * m);

    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;

      a--;
      b--;

      g[a].push_back(b);
      g[b].push_back(a);

      int id1 = 2 * i;
      int id2 = 2 * i + 1;

      sa[id1] = a;
      sb[id1] = b;

      sa[id2] = b;
      sb[id2] = a;

      id[key(a, b)] = id1;
      id[key(b, a)] = id2;
    }

    vector<int> dx = bfs(x, g);
    vector<int> dz = bfs(z, g);

    const int INF = INT_MAX / 4;

    vector<int> dist(2 * m, INF);
    vector<bool> used(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    auto relax = [&](int s, int nd) {
      if (nd >= dist[s]) return;

      dist[s] = nd;
      pq.push({nd, s});
    };

    for (int p : g[w]) {
      int s = id[key(p, w)];
      relax(s, dx[p] + 1);
    }

    while (!pq.empty()) {
      auto [d, s] = pq.top();
      pq.pop();

      if (d != dist[s]) continue;

      int a = sa[s], b = sb[s];

      relax(id[key(b, a)], d + 1);

      if (g[a].size() < g[b].size()) {
        for (int c : g[a]) {
          if (c == b) continue;

          if (id.find(key(b, c)) != id.end()) relax(id[key(c, a)], d + 2);
        }
      } else {
        for (int c : g[b]) {
          if (c == a) continue;

          if (id.find(key(a, c)) != id.end()) relax(id[key(c, a)], d + 2);
        }
      }

      if (!used[a]) {
        used[a] = true;

        for (int c : g[a]) relax(id[key(c, a)], d + 3);
      }
    }

    int ans = INF;

    if (w == y) ans = dx[z];

    for (int p : g[y]) {
      int s = id[key(y, p)];
      ans = min(ans, dist[s] + dz[p]);
    }

    cout << ans << '\n';
  }

  return 0;
}
