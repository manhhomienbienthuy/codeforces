/*!
 * author: manhhomienbienthuy
 * created: 2026-07-31T03:13:59+00:00
 * https://codeforces.com/gym/106628/problem/N
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> k(n + 1);

    for (int i = 1; i <= n; i++) {
      cin >> k[i];
    }

    vector<vector<pair<int, int>>> g(n + 1);

    for (int v = 2; v <= n; v++) {
      int p, w;
      cin >> p >> w;

      g[p].push_back({v, w});
    }

    vector<int> dep(n + 1);

    vector<vector<int>> ancestor(n + 1, vector<int>(MAX));
    vector<vector<int>> mx(n + 1, vector<int>(MAX));
    vector<vector<int>> mn(n + 1, vector<int>(MAX, INT_MAX));

    vector<int> ord;
    ord.reserve(n);

    stack<int> st;
    st.push(1);

    while (!st.empty()) {
      int v = st.top();
      st.pop();

      ord.push_back(v);

      for (auto [to, w] : g[v]) {
        dep[to] = dep[v] + 1;

        ancestor[to][0] = v;
        mx[to][0] = w;
        mn[to][0] = w;

        st.push(to);
      }
    }

    for (int j = 1; j < MAX; j++) {
      for (int i = 1; i <= n; i++) {
        int p = ancestor[i][j - 1];
        if (p == -1) continue;

        ancestor[i][j] = ancestor[p][j - 1];
        mx[i][j] = max(mx[i][j - 1], mx[p][j - 1]);
        mn[i][j] = min(mn[i][j - 1], mn[p][j - 1]);
      }
    }

    auto get_ancestor = [&](int v, int k) {
      for (int j = 0; j < MAX; j++) {
        if ((k >> j) & 1) {
          v = ancestor[v][j];
        }
      }

      return v;
    };

    auto calc = [&](int u, int v) {
      int mxv = 0;
      int mnv = INT_MAX;

      int d = dep[v] - dep[u];

      for (int j = MAX - 1; j >= 0; j--) {
        if ((d >> j) & 1) {
          mxv = max(mxv, mx[v][j]);
          mnv = min(mnv, mn[v][j]);
          v = ancestor[v][j];
        }
      }

      return pair<int, int>{mxv, mnv};
    };

    vector<int64_t> ans(n + 1);

    for (int v = 1; v <= n; v++) {
      int lo = 0;
      int hi = dep[v];

      while (lo <= hi) {
        int mid = (lo + hi) / 2;

        int u = get_ancestor(v, dep[v] - mid);

        auto [mxv, mnv] = calc(u, v);

        int64_t diff = (u == v ? 0 : mxv - mnv);

        if (diff <= k[v]) {
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }

      int h = get_ancestor(v, dep[v] - hi - 1);

      ans[v]++;

      if (h != 1) {
        ans[ancestor[h][0]]--;
      }
    }

    for (int i = (int)ord.size() - 1; i >= 0; i--) {
      int v = ord[i];

      for (auto [to, w] : g[v]) {
        ans[v] += ans[to];
      }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
  }

  return 0;
}
