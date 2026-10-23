/*!
 * author: manhhomienbienthuy
 * created: 2026-10-22T08:53:40+00:00
 * https://codeforces.com/gym/106764/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  int64_t T;
  cin >> n >> T;

  vector<int64_t> t(n);
  for (int64_t& x : t) cin >> x;

  vector<int> b(n);
  for (int& x : b) cin >> x;

  vector<vector<int>> g(n);

  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;

    while (m--) {
      int x;
      cin >> x;
      g[i].push_back(x - 1);
    }
  }

  vector<int> ord;
  stack<int> st;
  st.push(0);

  while (!st.empty()) {
    int v = st.top();
    st.pop();

    ord.push_back(v);

    for (int u : g[v]) st.push(u);
  }

  reverse(ord.begin(), ord.end());

  auto check = [&](int64_t x) {
    vector<int64_t> dp(n);

    for (int v : ord) {
      int64_t cur = 0;

      for (int u : g[v]) cur = max(cur, dp[u]);

      cur += b[v] ? t[v] / x : t[v];

      if (cur > T) return false;

      dp[v] = cur;
    }

    return true;
  };

  int64_t lo = 1, hi = 1e9 + 1;

  if (!check(hi)) {
    cout << -1 << '\n';
    return 0;
  }

  while (lo <= hi) {
    int64_t mid = (lo + hi) >> 1;

    if (check(mid))
      hi = mid - 1;
    else
      lo = mid + 1;
  }

  cout << lo << '\n';

  return 0;
}
