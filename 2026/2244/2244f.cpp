/*!
 * author: manhhomienbienthuy
 * created: 2026-07-15T06:28:38+00:00
 * https://codeforces.com/contest/2244/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

struct info {
  int64_t mn, mx, cnt;
  bool ok;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      tree[p].push_back(i);
    }

    vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> q;

    stack<int> st;
    st.push(1);
    while (!st.empty()) {
      int v = st.top();
      st.pop();
      q.push_back(v);
      for (int u : tree[v]) st.push(u);
    }

    vector<info> dp(n + 1);

    for (int i = (int)q.size() - 1; i >= 0; i--) {
      int v = q[i];

      if (tree[v].empty()) {
        dp[v] = {a[v], a[v], 1, true};
        continue;
      }

      bool ok = true;
      int64_t mn = LLONG_MAX, mx = LLONG_MIN, cnt = 0;

      for (int u : tree[v]) {
        ok &= dp[u].ok;
        mn = min(mn, dp[u].mn);
        mx = max(mx, dp[u].mx);
        cnt += dp[u].cnt;
      }

      if (mx - mn + 1 != cnt) ok = false;

      int m = (int)tree[v].size();
      if (m > 1) {
        int bad = 0;

        for (int j = 0; j < m; j++) {
          int u = tree[v][j];
          int w = tree[v][(j + 1) % m];

          bad += dp[w].mn != dp[u].mx + 1;
        }

        if (bad > 1) ok = false;
      }

      dp[v] = {mn, mx, cnt, ok};
    }

    cout << (dp[1].ok ? "YES\n" : "NO\n");
  }

  return 0;
}
