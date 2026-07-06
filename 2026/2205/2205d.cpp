/*!
 * author: manhhomienbienthuy
 * created: 2026-07-06T01:52:29+00:00
 * https://codeforces.com/contest/2205/problem/D
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
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    vector<int> parent(n, -1), left(n, -1), right(n, -1);
    stack<int> st;
    int root = -1;
    for (int i = 0; i < n; i++) {
      int last = -1;
      while (!st.empty() && a[st.top()] < a[i]) {
        last = st.top();
        st.pop();
      }

      if (st.empty()) {
        root = i;
      } else {
        parent[i] = st.top();
        right[st.top()] = i;
      }

      if (last != -1) {
        parent[last] = i;
        left[i] = last;
      }

      st.push(i);
    }

    vector<int> q = {root};
    for (int i = 0; i < (int)q.size(); i++) {
      int u = q[i];
      if (left[u] != -1) q.push_back(left[u]);
      if (right[u] != -1) q.push_back(right[u]);
    }
    reverse(q.begin(), q.end());

    vector<int> sz(n, 0), dp(n, 0);
    for (auto u : q) {
      int sz_left = left[u] == -1 ? 0 : sz[left[u]];
      int sz_right = right[u] == -1 ? 0 : sz[right[u]];
      sz[u] = 1 + sz_left + sz_right;

      int dp_left = left[u] == -1 ? 0 : dp[left[u]];
      int dp_right = right[u] == -1 ? 0 : dp[right[u]];
      dp[u] = min(sz_right + dp_left, sz_left + dp_right);
    }

    cout << dp[root] << '\n';
  }

  return 0;
}
