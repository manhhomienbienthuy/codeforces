/*!
 * author: manhhomienbienthuy
 * created: 2026-11-04T15:15:07+00:00
 * https://codeforces.com/contest/2283/problem/D
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

    if (!(n & 1)) {
      for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
      }

      cout << n + 1 << '\n';
      continue;
    }

    vector<int> head(n, -1), to, nxt;

    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;

      u--;
      v--;

      to.push_back(v);
      nxt.push_back(head[u]);
      head[u] = (int)to.size() - 1;

      to.push_back(u);
      nxt.push_back(head[v]);
      head[v] = (int)to.size() - 1;
    }

    vector<pair<int, int>> cand = {
        {n, n - 1},
        {n + 1, n / 2},
        {n + 2, 0},
    };

    int ans = n;

    for (auto& [k, x] : cand) {
      vector<int> comp(n, -1);
      comp[x] = -2;

      int e = head[x], cid = 0;

      while (e != -1) {
        int root = to[e];

        if (comp[root] == -1) {
          comp[root] = cid;

          stack<int> st;
          st.push(root);

          while (!st.empty()) {
            int v = st.top();
            st.pop();

            int j = head[v];

            while (j != -1) {
              int u = to[j];

              if (comp[u] == -1) {
                comp[u] = cid;
                st.push(u);
              }

              j = nxt[j];
            }
          }

          cid++;
        }

        e = nxt[e];
      }

      bool gray = false;

      for (int u = 0; u < n; u++) {
        int v = k - u - 2;

        if (v < 0 || v >= n || u >= v) continue;

        if (comp[u] != comp[v]) {
          gray = true;
          break;
        }
      }

      if (gray) {
        ans = k;
        break;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
