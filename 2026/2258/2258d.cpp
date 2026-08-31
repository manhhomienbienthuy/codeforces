/*!
 * author: manhhomienbienthuy
 * created: 2026-08-29T16:29:02+00:00
 * https://codeforces.com/contest/2258/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

struct segm {
  int64_t l, r;
};

struct node {
  int lc, rc;
  int cnt;
};

struct key_hash {
  size_t operator()(uint64_t x) const {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
  }
};

struct pst {
  int n;
  vector<node> tr;

  unordered_map<int, int> leaf;
  unordered_map<uint64_t, int, key_hash> inner;

  pst(int n) : n(n) {
    tr.push_back({0, 0, 0});
    leaf[0] = 0;
  }

  int get_leaf(int cnt) {
    auto it = leaf.find(cnt);

    if (it != leaf.end()) {
      return it->second;
    }

    int id = (int)tr.size();
    tr.push_back({0, 0, cnt});
    leaf[cnt] = id;

    return id;
  }

  int get_node(int lc, int rc) {
    if (lc == 0 && rc == 0) {
      return 0;
    }

    uint64_t key = (uint64_t)(uint32_t)lc << 32 | (uint32_t)rc;

    auto it = inner.find(key);

    if (it != inner.end()) {
      return it->second;
    }

    int id = (int)tr.size();

    tr.push_back({lc, rc, tr[lc].cnt + tr[rc].cnt});

    inner[key] = id;

    return id;
  }

  int add(int v, int l, int r, int pos) {
    if (l == r) {
      return get_leaf(tr[v].cnt + 1);
    }

    int m = (l + r) >> 1;
    int lc = tr[v].lc;
    int rc = tr[v].rc;

    if (pos <= m) {
      lc = add(lc, l, m, pos);
    } else {
      rc = add(rc, m + 1, r, pos);
    }

    return get_node(lc, rc);
  }

  bool better(int a, int b, int l, int r) const {
    if (a == b) {
      return false;
    }

    if (l == r) {
      return tr[a].cnt > tr[b].cnt;
    }

    int m = (l + r) >> 1;
    int ar = tr[a].rc;
    int br = tr[b].rc;

    if (ar != br) {
      return better(ar, br, m + 1, r);
    }

    return better(tr[a].lc, tr[b].lc, l, m);
  }

  void collect(int v, int l, int r, const vector<int64_t>& vals,
               vector<int64_t>& ans) const {
    if (v == 0) {
      return;
    }

    if (l == r) {
      for (int i = 0; i < tr[v].cnt; i++) {
        ans.push_back(vals[l]);
      }

      return;
    }

    int m = (l + r) >> 1;

    collect(tr[v].rc, m + 1, r, vals, ans);
    collect(tr[v].lc, l, m, vals, ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<segm> seg;
    seg.reserve(n + m);

    for (int col = 0; col < 2; col++) {
      int sz = col == 0 ? n : m;

      for (int i = 0; i < sz; i++) {
        int64_t l, r;
        cin >> l >> r;

        // Convert [l, r] to [l, r + 1).
        seg.push_back({l, r + 1});
      }
    }

    sort(seg.begin(), seg.end(), [&](const segm& a, const segm& b) {
      if (a.l != b.l) {
        return a.l < b.l;
      }

      return a.r > b.r;
    });

    vector<segm> a;

    for (auto [l, r] : seg) {
      if (!a.empty() && r <= a.back().r) {
        continue;
      }

      a.push_back({l, r});
    }

    vector<int64_t> pts;

    for (auto [l, r] : a) {
      pts.push_back(l);
      pts.push_back(r);
    }

    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    int p = (int)pts.size();

    vector<int> li(a.size());
    vector<int> ri(a.size());

    for (int i = 0; i < (int)a.size(); i++) {
      li[i] = (int)(lower_bound(pts.begin(), pts.end(), a[i].l) - pts.begin());

      ri[i] = (int)(lower_bound(pts.begin(), pts.end(), a[i].r) - pts.begin());
    }

    vector<int> lo(p, p);

    int ptr = 0;
    multiset<int> st;

    for (int i = 1; i < p; i++) {
      while (ptr < (int)a.size() && li[ptr] < i) {
        st.insert(li[ptr]);
        ptr++;
      }

      for (int j = 0; j < ptr; j++) {
        if (ri[j] >= i) {
          lo[i] = min(lo[i], li[j]);
        }
      }
    }

    vector<int64_t> vals;

    for (int i = 1; i < p; i++) {
      if (lo[i] == p) {
        continue;
      }

      for (int j = lo[i]; j < i; j++) {
        vals.push_back(pts[i] - pts[j]);
      }
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    pst tree((int)vals.size());

    vector<int> dp(p);
    dp[0] = 0;

    for (int i = 1; i < p; i++) {
      dp[i] = dp[i - 1];

      if (lo[i] == p) {
        continue;
      }

      for (int j = lo[i]; j < i; j++) {
        int64_t len = pts[i] - pts[j];

        int pos =
            (int)(lower_bound(vals.begin(), vals.end(), len) - vals.begin());

        int cur = tree.add(dp[j], 0, (int)vals.size() - 1, pos);

        if (tree.better(cur, dp[i], 0, (int)vals.size() - 1)) {
          dp[i] = cur;
        }
      }
    }

    vector<int64_t> ans;

    tree.collect(dp[p - 1], 0, (int)vals.size() - 1, vals, ans);

    cout << ans.size() << '\n';

    for (int64_t x : ans) {
      cout << x << ' ';
    }

    cout << '\n';
  }

  return 0;
}
