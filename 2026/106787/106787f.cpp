/*!
 * author: manhhomienbienthuy
 * created: 2026-11-06T02:11:40+00:00
 * https://codeforces.com/gym/106787/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

struct node {
  int l, r, p, cnt;
  vector<int> ch;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int n = (int)s.size();

  vector<node> tree(1, {-1, n, -1, 0, {}});
  vector<int> st = {0};

  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      int par = st.back(), v = (int)tree.size();

      tree.push_back({i, -1, par, 0, {}});
      tree[par].ch.push_back(v);
      st.push_back(v);
    } else if (s[i] == ')') {
      tree[st.back()].r = i;
      st.pop_back();
    } else {
      tree[st.back()].cnt++;
    }
  }

  for (int v = (int)tree.size() - 1; v > 0; v--) {
    tree[tree[v].p].cnt += tree[v].cnt;
  }

  int tot = tree[0].cnt;

  if (tot % 3) {
    cout << "impossible\n";
    return 0;
  }

  int q = tot / 3, a = -1, b = -1, best = -1;
  bool nested = false;

  for (int v = 1; v < (int)tree.size(); v++) {
    if (tree[v].cnt != q) continue;

    if (best != -1 && tree[best].r < tree[v].l) {
      a = best;
      b = v;
      break;
    }

    if (best == -1 || tree[v].r < tree[best].r) best = v;
  }

  if (a == -1) {
    vector<pair<int, bool>> dfs = {{0, false}};
    vector<int> active;

    while (!dfs.empty() && a == -1) {
      auto [v, exit] = dfs.back();
      dfs.pop_back();

      if (exit) {
        if (v && tree[v].cnt == 2 * q) {
          active.pop_back();
        }

        continue;
      }

      if (v && tree[v].cnt == q && !active.empty()) {
        a = active.back();
        b = v;
        nested = true;
        break;
      }

      dfs.push_back({v, true});

      if (v && tree[v].cnt == 2 * q) active.push_back(v);

      for (int i = (int)tree[v].ch.size() - 1; i >= 0; i--)
        dfs.push_back({tree[v].ch[i], false});
    }
  }

  if (a == -1) {
    cout << "impossible\n";
    return 0;
  }

  auto make = [&](int l, int r, vector<pair<int, int>> cut) {
    sort(cut.begin(), cut.end(),
         [&](auto& x, auto& y) { return tree[x.first].l < tree[y.first].l; });

    string res;
    int i = l, j = 0;

    while (i <= r) {
      if (j < (int)cut.size() && i == tree[cut[j].first].l) {
        res += '[';
        res += char('0' + cut[j].second);
        res += ']';

        i = tree[cut[j].first].r + 1;
        j++;
      } else {
        res += s[i];
        i++;
      }
    }

    return res;
  };

  string main_s, f1, f2;

  if (nested) {
    main_s = make(0, n - 1, {{a, 1}});
    f1 = make(tree[a].l + 1, tree[a].r - 1, {{b, 2}});
    f2 = make(tree[b].l + 1, tree[b].r - 1, {});
  } else {
    main_s = make(0, n - 1, {{a, 1}, {b, 2}});
    f1 = make(tree[a].l + 1, tree[a].r - 1, {});
    f2 = make(tree[b].l + 1, tree[b].r - 1, {});
  }

  cout << main_s << '\n';
  cout << "[1] " << f1 << '\n';
  cout << "[2] " << f2 << '\n';

  return 0;
}
