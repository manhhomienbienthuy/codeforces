/*!
 * author: manhhomienbienthuy
 * created: 2026-07-17T02:03:31+00:00
 * https://codeforces.com/contest/2245/problem/D1
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

    vector<int> sign(n + 1, 0);
    vector<tuple<int, int, int>> restricts;
    restricts.reserve(m);

    for (int k = 0; k < m; k++) {
      int o, i, j;
      cin >> o >> i >> j;
      if (i == j)
        sign[i] = (o == 1) ? 1 : -1;
      else
        restricts.push_back({o, i, j});
    }

    bool ok = true;
    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0);

    for (auto [o, i, j] : restricts) {
      int si = sign[i], sj = sign[j];
      if (si == sj) {
        if (si == 1 && o == 2) {
          ok = false;
          break;
        } else if (si == -1 && o == 1) {
          ok = false;
          break;
        }
      } else {
        int x = (si == 1) ? i : j, y = (si == -1) ? i : j;
        if (o == 1) {
          g[x].push_back(y);
          indeg[y]++;
        } else {
          g[y].push_back(x);
          indeg[x]++;
        }
      }
    }

    if (!ok) {
      cout << "NO\n";
      continue;
    }

    vector<int> ord;
    ord.reserve(n);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (!indeg[i]) q.push(i);
    }

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      ord.push_back(u);
      for (int v : g[u]) {
        if (!--indeg[v]) q.push(v);
      }
    }

    if ((int)ord.size() != n) {
      cout << "NO\n";
      continue;
    }

    vector<int> pos(n + 1);
    for (int k = 0; k < n; k++) pos[ord[k]] = k;

    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      int v = n - pos[i];
      cout << (sign[i] == 1 ? v : -v) << ' ';
    }
    cout << '\n';
  }

  return 0;
}
