/*!
 * author: manhhomienbienthuy
 * created: 2026-10-14T15:10:44+00:00
 * https://codeforces.com/contest/2276/problem/D
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

    vector<int> g(n);

    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      u--;
      v--;

      g[u]++;
      g[v]++;
    }

    bool isolate = false, center = false;

    for (int i = 0; i < n; i++) {
      if (!g[i]) {
        isolate = true;
        break;
      }

      if (m == n - 1) {
        if (g[i] == n - 1) {
          center = true;
          break;
        }
      }
    }

    if (isolate)
      cout << "Brain Melt\n";
    else if (center)
      cout << "2\n";
    else
      cout << "Many\n";
  }

  return 0;
}
