/*!
 * author: manhhomienbienthuy
 * created: 2026-10-17T15:34:36+00:00
 * https://codeforces.com/contest/2261/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    string s;

    cin >> n >> k >> s;

    int cnt = n >> 1;

    vector<int> parent(cnt, -1);
    vector<vector<int>> children(cnt);

    vector<int> depth(cnt), subtree_sz(cnt, 1), st;
    int idx = 0;

    for (char c : s) {
      if (c == '(') {
        if (!st.empty()) {
          int p = st.back();

          parent[idx] = p;
          depth[idx] = depth[p] + 1;
          children[p].push_back(idx);
        } else {
          depth[idx] = 1;
        }

        st.push_back(idx++);
      } else {
        st.pop_back();
      }
    }

    for (int i = cnt - 1; i >= 0; i--) {
      if (parent[i] != -1) subtree_sz[parent[i]] += subtree_sz[i];
    }

    vector<int> cost(cnt), pref(cnt);
    int prev = 0;

    for (int i = 0; i < cnt; i++) {
      if (parent[i] == -1) {
        pref[i] = prev;
        prev += subtree_sz[i];
      }
    }

    for (int i = 0; i < cnt; i++) {
      prev = 0;

      for (int x : children[i]) {
        cost[x] = cost[i] + prev;
        pref[x] = pref[i] + prev;

        prev += subtree_sz[x];
      }
    }

    int mx;
    for (mx = 1; (1 << mx) <= cnt; mx++);

    vector up(mx, vector<int>(cnt, -1));

    for (int i = 0; i < cnt; i++) up[0][i] = parent[i];

    for (int level = 1; level < mx; level++) {
      for (int i = 0; i < cnt; i++) {
        int middle = up[level - 1][i];

        if (middle != -1) up[level][i] = up[level - 1][middle];
      }
    }

    int pref_mx = 0, depth_mx = 0;

    for (int i = 0; i < cnt; i++) {
      if (pref[i] <= k) pref_mx = max(pref_mx, depth[i]);

      idx = i;

      for (int level = mx - 1; level >= 0; level--) {
        int ancestor = up[level][idx];

        if (ancestor != -1 && cost[ancestor] >= cost[i] - k) {
          idx = ancestor;
        }
      }

      depth_mx = max(depth_mx, depth[i] - depth[idx] + 1);
    }

    cout << max(depth_mx, min(cnt, k + pref_mx)) << '\n';
  }

  return 0;
}
