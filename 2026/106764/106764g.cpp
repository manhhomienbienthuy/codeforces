/*!
 * author: manhhomienbienthuy
 * created: 2026-10-23T13:57:30+00:00
 * https://codeforces.com/gym/106764/problem/G
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> edge(n);
  vector<vector<int>> g(26);
  vector<int> diff(26);
  vector<bool> used(26);

  for (int i = 0; i < n; i++) {
    string f;
    cin >> f;

    int u = f.front() - 'a', v = f.back() - 'a';

    edge[i] = {u, v};

    diff[u]++;
    diff[v]--;

    g[u].push_back(v);
    g[v].push_back(u);

    used[u] = true;
    used[v] = true;
  }

  int root = -1;

  for (int v = 0; v < 26; v++) {
    if (used[v]) {
      root = v;
      break;
    }
  }

  vector<bool> visisted(26);
  stack<int> st;

  st.push(root);
  while (!st.empty()) {
    int v = st.top();
    st.pop();

    visisted[v] = true;

    for (int u : g[v]) {
      if (!visisted[u]) st.push(u);
    }
  }

  for (int v = 0; v < 26; v++) {
    if (used[v] && !visisted[v]) {
      cout << "NO\n";
      return 0;
    }
  }

  auto check = [&]() {
    bool plus = false, minus = false;

    for (int x : diff) {
      if (x == 1) {
        if (plus) return false;
        plus = true;
      } else if (x == -1) {
        if (minus) return false;
        minus = true;
      } else if (x)
        return false;
    }

    return true;
  };

  if (check()) {
    cout << "YES -1\n";
    return 0;
  }

  for (int i = 0; i < n; i++) {
    auto [u, v] = edge[i];

    diff[u] -= 2;
    diff[v] += 2;

    if (check()) {
      cout << "YES " << i + 1 << '\n';
      return 0;
    }

    diff[u] += 2;
    diff[v] -= 2;
  }

  cout << "NO\n";
  return 0;
}
