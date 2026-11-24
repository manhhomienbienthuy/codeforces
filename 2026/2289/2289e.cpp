/*!
 * author: manhhomienbienthuy
 * created: 2026-11-24T02:13:12+00:00
 * https://codeforces.com/contest/2289/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, d;
    cin >> n >> d;

    int tot = 2 * n - 1;

    vector<pair<int, int>> child(tot, {-1, -1});
    vector<int> parent(tot, -1), depth(tot), ans(n);

    for (int v = n; v < tot; v++) {
      int a, b;
      cin >> a >> b;

      a--;
      b--;

      child[v] = {a, b};
      parent[a] = parent[b] = v;
    }

    int root = tot - 1;

    stack<int> stk;
    stk.push(root);

    while (!stk.empty()) {
      int v = stk.top();
      stk.pop();

      if (v < n) continue;

      auto [a, b] = child[v];

      depth[a] = depth[v] + 1;
      depth[b] = depth[v] + 1;

      stk.push(a);
      stk.push(b);
    }

    vector<set<int>*> win(tot);

    for (int v = 0; v < n; v++) {
      win[v] = new set<int>();
      win[v]->insert(v + 1);
    }

    for (int v = n; v < tot; v++) {
      auto [a, b] = child[v];

      set<int>* sa = win[a];
      set<int>* sb = win[b];

      int mx_a = *sa->rbegin();
      int mx_b = *sb->rbegin();

      int lim_a = mx_b + d;
      int lim_b = mx_a + d;

      auto it_a = sa->lower_bound(lim_a);

      while (it_a != sa->end()) {
        int x = *it_a;
        ans[x - 1] = depth[x - 1] - depth[v];
        it_a = sa->erase(it_a);
      }

      auto it_b = sb->lower_bound(lim_b);

      while (it_b != sb->end()) {
        int x = *it_b;
        ans[x - 1] = depth[x - 1] - depth[v];
        it_b = sb->erase(it_b);
      }

      if (sa->size() < sb->size()) swap(sa, sb);

      for (int x : *sb) sa->insert(x);

      delete sb;
      win[v] = sa;
    }

    for (int x : *win[root]) {
      ans[x - 1] = depth[x - 1];
    }

    delete win[root];

    for (int x : ans) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}
