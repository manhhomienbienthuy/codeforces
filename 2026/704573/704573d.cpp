/*!
 * author: manhhomienbienthuy
 * created: 2026-07-21T02:39:44+00:00
 * https://codeforces.com/gym/704573/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

struct info {
  int id;
  int64_t hotel;
  int64_t hospital;
  int64_t h;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, x, k;
  cin >> n >> m >> x >> k;

  vector<info> hs(k);
  for (int i = 0; i < k; i++) {
    cin >> hs[i].id >> hs[i].hotel >> hs[i].hospital >> hs[i].h;
  }

  vector<vector<pair<int, int64_t>>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    int64_t w;
    cin >> u >> v >> w;

    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  vector<int64_t> dist(n + 1, LLONG_MAX);
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> pq;

  dist[0] = 0;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (d != dist[u]) continue;

    for (auto [v, w] : g[u]) {
      if (dist[v] > d + w) {
        dist[v] = d + w;
        pq.push({dist[v], v});
      }
    }
  }

  int64_t need = 4LL * x;
  int64_t ans = LLONG_MAX;

  for (auto& cur : hs) {
    if (dist[cur.id] == LLONG_MAX) continue;

    int64_t days = (need + cur.h - 1) / cur.h;
    int64_t cost = dist[cur.id] + days * (cur.hotel + cur.hospital);
    ans = min(ans, cost);
  }

  cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
  return 0;
}
