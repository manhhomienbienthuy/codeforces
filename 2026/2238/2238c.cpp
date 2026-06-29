/*!
 * author: manhhomienbienthuy
 * created: 2026-06-29T00:13:26+00:00
 * https://codeforces.com/contest/2238/problem/C
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
    vector<int> p(n + 1);
    vector<vector<int>> tree(n + 1);
    for (int i = 2; i <= n; i++) {
      cin >> p[i];
      tree[p[i]].push_back(i);
    }

    vector<int> dep(n + 1, 0);
    for (int i = 2; i <= n; i++) dep[i] = dep[p[i]] + 1;

    vector<int> mx = dep;
    for (int i = n; i >= 1; i--)
      if (p[i]) mx[p[i]] = max(mx[p[i]], mx[i]);

    int64_t ans = n;
    for (int u = 1; u <= n; u++) {
      if (tree[u].size() < 2) continue;
      int m1 = 0, m2 = 0;
      for (auto v : tree[u]) {
        int m = mx[v];
        if (m > m1) {
          m2 = m1;
          m1 = m;
        } else if (m > m2)
          m2 = m;
      }
      ans += m2 - dep[u];
    }

    cout << ans << '\n';
  }
  return 0;
}

/*
         1
   2           3
4     5     6     7
8 9 10 11 12 13 14 15
=> 26
for each u: nodes + maxdepth (not alone)
*/
