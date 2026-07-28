/*!
 * author: manhhomienbienthuy
 * template C++ for Codeforces
 */

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// power of 2
int64_t power(int64_t p) {
  if (p < 30) return (1 << p) % MOD;
  int64_t r = power(p / 2);
  return (r * r * (1 << (p & 1))) % MOD;
}

// power of a
int64_t power(int64_t a, int64_t p) {
  int64_t r = 1;
  while (p > 0) {
    if (p & 1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    p >>= 1;
  }
  return r;
}

// get MSB
int64_t setBitNumber(int64_t n) {
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n |= n >> 32;
  n = (n >> 1) + 1;
  return n;
}

const int MAX = 510000;
int64_t fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void fact_init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// longest common subsequence
int lcs(vector<int>& s1, vector<int>& s2) {
  int n = s1.size();
  int m = s2.size();

  // Initializing a matrix of size (m+1)*(n+1)
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  // Building dp[m+1][n+1] in bottom-up fashion
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  // dp[m][n] contains length of LCS for s1[0..m-1]
  // and s2[0..n-1]
  return dp[n][m];
}

// longest increasing subsequence
int find_lis(const vector<int>& a) {
  vector<int> dp;
  for (int i : a) {
    int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
    if (pos == dp.size()) {
      // we can have a new, longer increasing subsequence!
      dp.push_back(i);
    } else {
      // oh ok, at least we can make the ending element smaller
      dp[pos] = i;
    }
  }

  return dp.size();
}

struct rolling_hash {
  static const int MOD1 = 1000000007;
  static const int MOD2 = 1000000009;
  static const int BASE1 = 91138233;
  static const int BASE2 = 97266353;

  int n;
  vector<int> h1, h2, p1, p2;

  rolling_hash(const string& s) {
    n = (int)s.size();

    h1.assign(n + 1, 0);
    h2.assign(n + 1, 0);
    p1.assign(n + 1, 1);
    p2.assign(n + 1, 1);

    for (int i = 0; i < n; i++) {
      int x = s[i];

      h1[i + 1] = (int)((1ll * h1[i] * BASE1 + x) % MOD1);
      h2[i + 1] = (int)((1ll * h2[i] * BASE2 + x) % MOD2);

      p1[i + 1] = (int)((1ll * p1[i] * BASE1) % MOD1);
      p2[i + 1] = (int)((1ll * p2[i] * BASE2) % MOD2);
    }
  }

  pair<int, int> get(int l, int r) const {
    int x1 = (int)((h1[r] - 1ll * h1[l] * p1[r - l] % MOD1 + MOD1) % MOD1);

    int x2 = (int)((h2[r] - 1ll * h2[l] * p2[r - l] % MOD2 + MOD2) % MOD2);

    return {x1, x2};
  }
};

int lcp(const rolling_hash& rh, int a, int b, int mx) {
  int lo = 0, hi = mx;

  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;

    if (rh.get(a, a + mid) == rh.get(b, b + mid))
      lo = mid;
    else
      hi = mid - 1;
  }

  return lo;
}

struct fenwick {
  int n;
  vector<int64_t> bit;

  fenwick(int n_) : n(n_), bit(n + 1, 0) {}

  void add(int idx, int64_t val) {
    for (; idx <= n; idx += idx & -idx) {
      bit[idx] += val;
    }
  }

  int64_t sum(int idx) {
    int64_t res = 0;

    for (; idx > 0; idx -= idx & -idx) {
      res += bit[idx];
    }

    return res;
  }

  int64_t query(int l, int r) {
    if (l > r) return 0;
    return sum(r) - (l ? sum(l - 1) : 0);
  }
};

struct FastHash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

struct seg_tree {
  int n;
  vector<int> st;

  seg_tree(int n) : n(n), st(4 * n, 0) {}

  void update(int v, int l, int r, int pos, int val) {
    if (l == r) {
      st[v] = val;
      return;
    }

    int m = (l + r) >> 1;

    if (pos <= m) {
      update(v << 1, l, m, pos, val);
    } else {
      update(v << 1 | 1, m + 1, r, pos, val);
    }

    st[v] = max(st[v << 1], st[v << 1 | 1]);
  }

  int query(int v, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) {
      return INT_MIN;
    }

    if (ql <= l && r <= qr) {
      return st[v];
    }

    int m = (l + r) >> 1;

    return max(query(v << 1, l, m, ql, qr),
               query(v << 1 | 1, m + 1, r, ql, qr));
  }
};

struct lazy_seg {
  int n;
  vector<int64_t> mx, lazy;

  lazy_seg(int n_) : n(n_), mx(4 * n), lazy(4 * n) {}

  void apply(int v, int64_t val) {
    mx[v] += val;
    lazy[v] += val;
  }

  void push(int v) {
    if (lazy[v] == 0) return;

    apply(v << 1, lazy[v]);
    apply(v << 1 | 1, lazy[v]);

    lazy[v] = 0;
  }

  void add(int v, int l, int r, int ql, int qr, int64_t val) {
    if (ql > r || qr < l) return;

    if (ql <= l && r <= qr) {
      apply(v, val);
      return;
    }

    push(v);

    int m = (l + r) >> 1;

    add(v << 1, l, m, ql, qr, val);
    add(v << 1 | 1, m + 1, r, ql, qr, val);

    mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
  }

  int64_t query(int v, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) {
      return INT64_MIN;
    }

    if (ql <= l && r <= qr) {
      return mx[v];
    }

    push(v);

    int m = (l + r) >> 1;

    return max(query(v << 1, l, m, ql, qr),
               query(v << 1 | 1, m + 1, r, ql, qr));
  }
};

struct dsu {
  vector<int> p, sz;

  dsu(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }

  int find(int v) {
    if (p[v] == v) {
      return v;
    }

    return p[v] = find(p[v]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) {
      return false;
    }

    if (sz[a] < sz[b]) {
      swap(a, b);
    }

    p[b] = a;
    sz[a] += sz[b];

    return true;
  }
};

vector<int64_t> dijkstra(int n, vector<vector<pair<int, int>>>& g, int src) {
  vector<int64_t> dist(n, INT64_MAX);

  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> pq;

  dist[src] = 0;
  pq.push({0, src});

  while (!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();

    if (d != dist[v]) continue;

    for (auto [to, w] : g[v]) {
      if (dist[to] > d + w) {
        dist[to] = d + w;
        pq.push({dist[to], to});
      }
    }
  }

  return dist;
}

// KMP prefix
vector<int> prefix_func(const string& s) {
  int n = (int)s.size();

  vector<int> pi(n);

  for (int i = 1, j = 0; i < n; i++) {
    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }

    if (s[i] == s[j]) {
      j++;
    }

    pi[i] = j;
  }

  return pi;
}

// z function
vector<int> z_func(const string& s) {
  int n = (int)s.size();

  vector<int> z(n);

  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }

    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }

    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }

  return z;
}

// RMQ min ver
struct sparse_table {
  int n, lg;
  vector<int> lg2;
  vector<vector<int>> st;

  sparse_table(const vector<int>& a) {
    n = (int)a.size();

    lg2.resize(n + 1);
    lg2[1] = 0;

    for (int i = 2; i <= n; i++) {
      lg2[i] = lg2[i / 2] + 1;
    }

    lg = lg2[n] + 1;

    st.assign(lg, vector<int>(n));

    st[0] = a;

    for (int k = 1; k < lg; k++) {
      for (int i = 0; i + (1 << k) <= n; i++) {
        st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
      }
    }
  }

  int query(int l, int r) {
    int k = lg2[r - l + 1];

    return min(st[k][l], st[k][r - (1 << k) + 1]);
  }
};

// LCA (Binary Lifting)
struct lca_tree {
  int n, lg;
  vector<int> dep;
  vector<vector<int>> up;
  vector<vector<int>> g;

  lca_tree(int n) : n(n) {
    lg = 1;

    while ((1 << lg) <= n) {
      lg++;
    }

    dep.assign(n, 0);
    up.assign(lg, vector<int>(n));
    g.assign(n, vector<int>());
  }

  void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }

  void dfs(int v, int p) {
    up[0][v] = p;

    for (int k = 1; k < lg; k++) {
      up[k][v] = up[k - 1][up[k - 1][v]];
    }

    for (int to : g[v]) {
      if (to == p) {
        continue;
      }

      dep[to] = dep[v] + 1;

      dfs(to, v);
    }
  }

  void build(int root = 0) { dfs(root, root); }

  int kth(int v, int k) {
    for (int i = 0; i < lg; i++) {
      if (k & (1 << i)) {
        v = up[i][v];
      }
    }

    return v;
  }

  int lca(int a, int b) {
    if (dep[a] < dep[b]) {
      swap(a, b);
    }

    a = kth(a, dep[a] - dep[b]);

    if (a == b) {
      return a;
    }

    for (int i = lg - 1; i >= 0; i--) {
      if (up[i][a] != up[i][b]) {
        a = up[i][a];
        b = up[i][b];
      }
    }

    return up[0][a];
  }

  int dist(int a, int b) {
    int c = lca(a, b);

    return dep[a] + dep[b] - 2 * dep[c];
  }
};

// Topological Sort (Kahn's Algorithm)
vector<int> topo_sort(int n, vector<vector<int>>& g) {
  vector<int> indeg(n);

  for (int v = 0; v < n; v++) {
    for (int to : g[v]) {
      indeg[to]++;
    }
  }

  queue<int> q;

  for (int i = 0; i < n; i++) {
    if (indeg[i] == 0) {
      q.push(i);
    }
  }

  vector<int> ord;

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    ord.push_back(v);

    for (int to : g[v]) {
      indeg[to]--;

      if (indeg[to] == 0) {
        q.push(to);
      }
    }
  }

  return ord;
}

// literal encoding: lit(i, true)=2*i, lit(i, false)=2*i+1
struct TwoSat {
  int n;
  vector<vector<int>> g, rg;
  vector<int> ord, comp;
  vector<bool> vis;

  TwoSat(int n)
      : n(n), g(2 * n), rg(2 * n), comp(2 * n, -1), vis(2 * n, false) {}

  // add clause (x_u = f) OR (x_v = gv)
  void add_clause(int u, bool f, int v, bool gv) {
    // NOT lit(u,f) → lit(v,gv)  and  NOT lit(v,gv) → lit(u,f)
    // NOT lit(i,b) = lit(i, !b) = 2*i + b (since lit(i,b) = 2*i + !b)
    int nu = 2 * u + (int)f;    // literal for NOT(x_u=f)
    int lv = 2 * v + (int)!gv;  // literal for (x_v=gv)
    int nv = 2 * v + (int)gv;   // literal for NOT(x_v=gv)
    int lu = 2 * u + (int)!f;   // literal for (x_u=f)
    g[nu].push_back(lv);
    g[nv].push_back(lu);
    rg[lv].push_back(nu);
    rg[lu].push_back(nv);
  }

  void dfs1(int s) {
    stack<pair<int, int>> st;
    st.push({s, 0});
    vis[s] = true;
    while (!st.empty()) {
      auto& [v, idx] = st.top();
      if (idx < (int)g[v].size()) {
        int u = g[v][idx++];
        if (!vis[u]) {
          vis[u] = true;
          st.push({u, 0});
        }
      } else {
        ord.push_back(v);
        st.pop();
      }
    }
  }

  void dfs2(int s, int c) {
    stack<int> st;
    st.push(s);
    comp[s] = c;
    while (!st.empty()) {
      int v = st.top();
      st.pop();
      for (int u : rg[v])
        if (comp[u] < 0) {
          comp[u] = c;
          st.push(u);
        }
    }
  }

  bool solve(vector<bool>& val) {
    for (int i = 0; i < 2 * n; i++)
      if (!vis[i]) dfs1(i);
    int c = 0;
    for (int i = 2 * n - 1; i >= 0; i--)
      if (comp[ord[i]] < 0) dfs2(ord[i], c++);
    val.resize(n);
    for (int i = 0; i < n; i++) {
      if (comp[2 * i] == comp[2 * i + 1]) return false;
      // x_i = true if its "true literal" (2*i) has higher topo order (higher
      // comp)
      val[i] = comp[2 * i] > comp[2 * i + 1];
    }
    return true;
  }
};

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

    // coordinate compression
    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = (int)vals.size();

    auto gid = [&](int x) {
      return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
    };

    /*
    Monotonic Queue
    Useful for:
    - Sliding window minimum
    - Sliding window maximum
    - DP optimizations
    */
    deque<int> dq;
    int k;

    for (int i = 0; i < n; i++) {
      while (!dq.empty() && a[dq.back()] >= a[i]) {
        dq.pop_back();
      }

      dq.push_back(i);

      while (!dq.empty() && dq.front() <= i - k) {
        dq.pop_front();
      }

      if (i >= k - 1) {
        int mn = a[dq.front()];
      }
    }
  }

  return 0;
}
