/*!
 * author: manhhomienbienthuy
 * created: 2026-08-18T02:06:46+00:00
 * https://codeforces.com/contest/2257/problem/C
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

    vector<vector<int>> g(n + 1);

    for (int v = 2; v <= n; v++) {
      int p;
      cin >> p;
      g[p].push_back(v);
    }

    int m;
    cin >> m;

    vector<bool> dam(n + 1);
    for (int i = 0; i < m; i++) {
      int v;
      cin >> v;
      dam[v] = true;
    }

    deque<int> dq;
    dq.push_back(1);

    vector<int> q;

    while (!dq.empty()) {
      int v = dq.front();
      dq.pop_front();

      q.push_back(v);

      for (int u : g[v]) dq.push_back(u);
    }

    cout << m - 1;

    for (int i = (int)q.size() - 1, j = 0; j < m - 1 && i >= 0; i--) {
      if (dam[q[i]]) {
        cout << ' ' << q[i];
        j++;
      }
    }

    cout << '\n';
  }

  return 0;
}
