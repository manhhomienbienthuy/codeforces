/*!
 * author: manhhomienbienthuy
 * created: 2026-09-26T15:43:51+00:00
 * https://codeforces.com/contest/2269/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

const int B = 18;

struct trie_node {
  int ch[2] = {0, 0};
  int cnt = 0;
};

vector<trie_node> tr;

int clone_tr(int v) {
  tr.push_back(tr[v]);
  return (int)tr.size() - 1;
}

int add(int old, int x) {
  int root = clone_tr(old);
  int u = root;
  tr[u].cnt++;

  for (int b = B - 1; b >= 0; b--) {
    int d = x >> b & 1;
    int nxt = clone_tr(tr[u].ch[d]);

    tr[u].ch[d] = nxt;
    u = nxt;
    tr[u].cnt++;
  }

  return root;
}

int cnt(int r, int l) { return tr[r].cnt - tr[l].cnt; }

int query(int rr, int ll, int x, int mask) {
  vector<pair<int, int>> cur = {{rr, ll}};
  int ans = 0;

  for (int b = B - 1; b >= 0; b--) {
    int xb = x >> b & 1;

    if (mask >> b & 1) {
      vector<pair<int, int>> nxt;
      int want = xb ^ 1;

      for (auto [r, l] : cur) {
        int nr = tr[r].ch[want];
        int nl = tr[l].ch[want];

        if (cnt(nr, nl) > 0) {
          nxt.push_back({nr, nl});
        }
      }

      if (!nxt.empty()) {
        ans |= 1 << b;
        cur.swap(nxt);
      } else {
        nxt.clear();
        want = xb;

        for (auto [r, l] : cur) {
          int nr = tr[r].ch[want];
          int nl = tr[l].ch[want];

          if (cnt(nr, nl) > 0) {
            nxt.push_back({nr, nl});
          }
        }

        cur = move(nxt);
      }
    } else {
      vector<pair<int, int>> nxt;

      for (auto [r, l] : cur) {
        for (int d = 0; d < 2; d++) {
          int nr = tr[r].ch[d];
          int nl = tr[l].ch[d];

          if (cnt(nr, nl) > 0) {
            nxt.push_back({nr, nl});
          }
        }
      }

      cur = move(nxt);
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] ^ a[i];
    }

    vector<int> lc(n, -1), rc(n, -1), par(n, -1);
    vector<int> stk;

    for (int i = 0; i < n; i++) {
      int last = -1;

      while (!stk.empty() && a[stk.back()] < a[i]) {
        last = stk.back();
        stk.pop_back();
      }

      if (!stk.empty()) {
        rc[stk.back()] = i;
        par[i] = stk.back();
      }

      if (last != -1) {
        lc[i] = last;
        par[last] = i;
      }

      stk.push_back(i);
    }

    int root = 0;
    while (par[root] != -1) root = par[root];

    vector<int> ord;
    stk = {root};

    while (!stk.empty()) {
      int v = stk.back();
      stk.pop_back();
      ord.push_back(v);

      if (lc[v] != -1) stk.push_back(lc[v]);
      if (rc[v] != -1) stk.push_back(rc[v]);
    }

    vector<int> L(n), R(n);

    for (int i = n - 1; i >= 0; i--) {
      int v = ord[i];

      L[v] = lc[v] == -1 ? v : L[lc[v]];
      R[v] = rc[v] == -1 ? v : R[rc[v]];
    }

    tr.clear();
    tr.reserve((n + 1) * (B + 1) + 1);
    tr.push_back(trie_node());

    vector<int> rt(n + 2);
    rt[0] = 0;

    for (int i = 0; i <= n; i++) {
      rt[i + 1] = add(rt[i], pref[i]);
    }

    auto range_query = [&](int l, int r, int x, int mask) {
      if (l > r) return 0;

      return query(rt[r + 1], rt[l], x, mask);
    };

    int ans = 0;

    for (int p = 0; p < n; p++) {
      int l1 = L[p];
      int r1 = p - 1;

      int l2 = p + 1;
      int r2 = R[p] + 1;

      int sz1 = r1 - l1 + 1;
      int sz2 = r2 - l2 + 1;

      if (sz1 > 0 && sz2 > 0) {
        if (sz1 <= sz2) {
          for (int i = l1; i <= r1; i++) {
            ans = max(ans, range_query(l2, r2, pref[i], a[p]));
          }
        } else {
          for (int i = l2; i <= r2; i++) {
            ans = max(ans, range_query(l1, r1, pref[i], a[p]));
          }
        }
      }

      if (p + 2 <= R[p] + 1) {
        ans = max(ans, range_query(p + 2, R[p] + 1, pref[p], a[p]));
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
