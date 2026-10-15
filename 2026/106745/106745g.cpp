/*!
 * author: manhhomienbienthuy
 * created: 2026-10-14T09:00:29+00:00
 * https://codeforces.com/gym/106745/problem/G
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string mode;
  cin >> mode;

  int t;
  cin >> t;

  if (mode == "first") {
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

      vector<int> col(n, -1), stk = {0};

      col[0] = 0;

      while (!stk.empty()) {
        int v = stk.back();
        stk.pop_back();

        for (int to : g[v]) {
          if (col[to] != -1) continue;

          col[to] = (col[v] + 1) % 3;
          stk.push_back(to);
        }
      }

      for (int x : col) cout << x << ' ';
      cout << '\n';
    }
  } else {
    while (t--) {
      int n;
      cin >> n;

      int m = 2 * n - 2;

      vector<int> c(m + 1), step(m);

      for (int& x : c) cin >> x;

      int sum = 0, mn = 0, pos = 0;

      for (int i = 0; i < m; i++) {
        step[i] = (c[i] + 1) % 3 == c[i + 1] ? 1 : -1;

        sum += step[i];

        if (sum < mn) {
          mn = sum;
          pos = i + 1;
        }
      }

      vector<int> stk = {1};
      int id = 1;

      for (int i = 0; i < m; i++) {
        int d = step[(pos + i) % m];

        if (d == 1) {
          int par = stk.back();
          int child = ++id;

          cout << par << ' ' << child << '\n';

          stk.push_back(child);
        } else {
          stk.pop_back();
        }
      }
    }
  }

  return 0;
}
