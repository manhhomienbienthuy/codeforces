/*!
 * author: manhhomienbienthuy
 * created: 2026-10-21T08:57:59+00:00
 * https://codeforces.com/gym/106745/problem/H
 */

#include <bits/stdc++.h>
using namespace std;

struct res {
  int far;
  vector<int> dist;
};

res bfs(const vector<vector<int>>& g, int src) {
  int n = (int)g.size();

  vector<int> dist(n, -1);
  queue<int> q;

  dist[src] = 0;
  q.push(src);

  int far = src;

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    if (dist[v] > dist[far]) far = v;

    for (int to : g[v]) {
      if (dist[to] != -1) continue;

      dist[to] = dist[v] + 1;
      q.push(to);
    }
  }

  return {far, move(dist)};
}

void first() {
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

    int a = bfs(g, 0).far;
    res res = bfs(g, a);

    int diam = res.dist[res.far];
    int root = a;

    if (diam % 2 == 1) root = g[a][0];

    vector<int> par(n, -1);
    vector<int> dep(n);
    vector<int> col(n);
    vector<int> stk = {root};

    par[root] = root;
    col[root] = 0;

    while (!stk.empty()) {
      int v = stk.back();
      stk.pop_back();

      for (int to : g[v]) {
        if (to == par[v]) continue;

        par[to] = v;
        dep[to] = dep[v] + 1;
        col[to] = col[v] ^ (dep[v] & 1);

        stk.push_back(to);
      }
    }

    for (int i = 0; i < n; i++) cout << col[i] << " \n"[i + 1 == n];
  }
}

bool restore(const vector<int>& c, int n, int k, vector<pair<int, int>>& ans) {
  int m = 2 * n - 2;

  vector<int> step(m);

  int dep = 0;
  int mn = 0;
  int pos = 0;

  for (int i = 0; i < m; i++) {
    int edge = c[i] ^ c[i + 1];

    if (edge == ((dep + k) & 1)) {
      step[i] = 1;
      dep++;
    } else {
      step[i] = -1;
      dep--;
    }

    if (dep < mn) {
      mn = dep;
      pos = i + 1;
    }
  }

  if (((mn + k) & 1) != 0) return false;

  ans.clear();

  vector<int> stk = {1};
  int cnt = 1;

  for (int j = 0; j < m; j++) {
    int i = (pos + j) % m;

    if (step[i] == 1) {
      cnt++;
      ans.push_back({stk.back(), cnt});
      stk.push_back(cnt);
    } else {
      if (stk.size() == 1) return false;

      stk.pop_back();
    }
  }

  return cnt == n && stk.size() == 1;
}

void second() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> c(2 * n - 1);

    for (int& x : c) cin >> x;

    if (n == 2) {
      cout << "1 2\n";
      continue;
    }

    vector<pair<int, int>> ans;

    for (int k = 0; k < 2; k++) {
      if (restore(c, n, k, ans)) break;
    }

    for (auto [u, v] : ans) cout << u << ' ' << v << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string t;
  cin >> t;

  if (t == "first")
    first();
  else
    second();

  return 0;
}
