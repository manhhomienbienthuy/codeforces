/*!
 * author: manhhomienbienthuy
 * created: 2026-10-29T07:32:52+00:00
 * https://codeforces.com/gym/106782/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  vector<vector<int>> g(n + 1);
  vector<pair<int, int>> comp;

  bool ok = true;

  for (int i = 1; i <= n; i++) {
    int d = 1 + a[i - 1] - a[i];

    if (d < 0 || d > 2) {
      ok = false;
      break;
    }

    if (d == 0) {
      comp.push_back({i, i});
    } else if (d == 1) {
      if (comp.empty()) {
        ok = false;
        break;
      }

      auto [l, r] = comp.back();
      comp.pop_back();

      g[i].push_back(l);
      g[l].push_back(i);

      comp.push_back({i, r});
    } else {
      if (comp.size() < 2) {
        ok = false;
        break;
      }

      auto [l1, r1] = comp.back();
      comp.pop_back();

      auto [l2, r2] = comp.back();
      comp.pop_back();

      g[i].push_back(l1);
      g[l1].push_back(i);

      g[i].push_back(l2);
      g[l2].push_back(i);

      comp.push_back({r1, r2});
    }

    if ((int)comp.size() != a[i]) {
      ok = false;
      break;
    }
  }

  if (!ok || comp.size() != 1) {
    cout << -1 << '\n';
    return 0;
  }

  int st = comp[0].first;

  vector<int> ord;
  ord.reserve(n);

  int par = 0;
  int v = st;

  while (v != 0) {
    ord.push_back(v);

    int nxt = 0;

    for (int to : g[v]) {
      if (to != par) {
        nxt = to;
        break;
      }
    }

    par = v;
    v = nxt;
  }

  if ((int)ord.size() != n) {
    cout << -1 << '\n';
    return 0;
  }

  vector<int> p(n + 1);
  for (int i = 1; i <= n; i++) p[ord[i - 1]] = i;

  for (int i = 1; i <= n; i++) cout << p[i] << ' ';
  cout << '\n';

  return 0;
}
