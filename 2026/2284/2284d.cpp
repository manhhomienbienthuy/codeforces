/*!
 * author: manhhomienbienthuy
 * created: 2026-11-06T15:31:14+00:00
 * https://codeforces.com/contest/2284/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

void first() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    vector<pair<int, int>> e;

    int r = -1;

    for (int i = 0; i < n - 1; i++) {
      if (s[i] == '1') {
        r = i;
        break;
      }
    }

    if (r == -1) {
      e.push_back({0, 1});
      e.push_back({1, 2});
      e.push_back({2, 0});

      for (int i = 3; i < n; i++) {
        e.push_back({0, i});
      }
    } else {
      for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0') {
          e.push_back({r, i});
        }
      }

      e.push_back({r, n - 1});

      for (int i = 0; i < n - 1; i++) {
        if (s[i] == '1' && i != r) {
          e.push_back({n - 1, i});
        }
      }
    }

    cout << e.size() << '\n';
    for (auto [u, v] : e) cout << u + 1 << ' ' << v + 1 << '\n';
  }
}

void second() {
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

    vector<int> color(n, -1);
    queue<int> q;

    color[0] = 0;
    q.push(0);

    bool ok = true;

    while (!q.empty()) {
      int v = q.front();
      q.pop();

      for (int to : g[v]) {
        if (color[to] == -1) {
          color[to] = color[v] ^ 1;
          q.push(to);
        } else if (color[to] == color[v]) {
          ok = false;
        }
      }
    }

    if (!ok) {
      cout << string(n - 1, '0') << '\n';
      return;
    }

    int flip = color[n - 1];

    for (int i = 0; i < n - 1; i++) cout << char('0' + (color[i] ^ flip));
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string mode;
  cin >> mode;

  if (mode == "first") {
    first();
  } else {
    second();
  }

  return 0;
}
