/*!
 * author: manhhomienbienthuy
 * created: 2026-07-17T02:03:31+00:00
 * https://codeforces.com/contest/2245/problem/D2
 */

#include <bits/stdc++.h>
using namespace std;

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
    int n, m;
    cin >> n >> m;

    TwoSat sat(n);
    vector<tuple<int, int, int>> cons;
    cons.reserve(m);

    for (int k = 0; k < m; k++) {
      int o, i, j;
      cin >> o >> i >> j;
      i--;
      j--;
      cons.emplace_back(o, i, j);
      if (o == 1)
        sat.add_clause(i, true, j, true);
      else
        sat.add_clause(i, false, j, false);
    }

    vector<bool> sgn;
    if (!sat.solve(sgn)) {
      cout << "NO\n";
      continue;
    }

    vector<vector<int>> dag(n);
    vector<int> indeg(n, 0);

    for (auto [o, i, j] : cons) {
      if (i == j) continue;
      if (sgn[i] == sgn[j]) continue;
      int P = sgn[i] ? i : j;
      int N = sgn[i] ? j : i;
      if (o == 1) {
        dag[P].push_back(N);
        indeg[N]++;
      } else {
        dag[N].push_back(P);
        indeg[P]++;
      }
    }

    vector<int> tord;
    tord.reserve(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
      if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      tord.push_back(u);
      for (int v : dag[u])
        if (--indeg[v] == 0) q.push(v);
    }

    if ((int)tord.size() != n) {
      cout << "NO\n";
      continue;
    }

    vector<int> pos(n);
    for (int k = 0; k < n; k++) pos[tord[k]] = k;

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      int v = n - pos[i];
      cout << (sgn[i] ? v : -v);
      if (i < n - 1) cout << ' ';
    }
    cout << '\n';
  }

  return 0;
}

/*
Hard version: n <= 2e5, m <= min(1e6, n(n+1)/2). Constraints may be sparse.

KEY DIFFERENCE from easy version:
- Not all pairs have constraints.
- Not all diagonals are constrained -> sign of element may be free.

ALGORITHM:

STEP 1: 2-SAT to determine sign assignment.
  Variable x_i: true = a_i >= 0 (P), false = a_i < 0 (N).
  Clauses from constraints:
    Diagonal (1,i,i): force x_i = true  => add_clause(lit_true(i), lit_true(i))
    Diagonal (2,i,i): force x_i = false => add_clause(lit_false(i),
lit_false(i)) Off-diag (1,i,j): x_i OR x_j     (PP always OK, NN+o=1 impossible)
    Off-diag (2,i,j): NOT x_i OR NOT x_j (NN always OK, PP+o=2 impossible)

  If 2-SAT unsatisfiable -> NO.

  WHY 2-SAT is sufficient for sign feasibility:
    PP+o=2 and NN+o=1 are the only same-sign contradictions.
    2-SAT clauses exactly capture these.

STEP 2: Build magnitude DAG for PN pairs (same as easy version).
  For constrained PN pair (P=positive element, N=negative element):
    o=1: edge P->N (v_P >= v_N)
    o=2: edge N->P (v_N > v_P, strict)

  If cycle exists -> NO.

  WHY cycle implies infeasibility regardless of sign choice:
    Signs around any magnitude cycle are FORCED by 2-SAT clauses:
    - P->N edge (from o=1): x_P OR x_N; since N is false, x_P must be true.
Can't flip P.
    - N->P edge (from o=2): NOT x_P OR NOT x_N; since P is true, x_N must be
false. Can't flip N. So if cycle exists in ANY valid 2-SAT solution, it exists
in ALL -> NO.

STEP 3: Topo sort, assign values n, n-1, ..., 1 by topo position.
  a_i = sgn[i] * (n - topo_pos[i])
  P elements: a_i = v_i >= 1 > 0 (satisfies >=0)
  N elements: a_i = -v_i <= -1 < 0 (satisfies <0)

COMPLEXITY: O(n + m) per test case.

CORRECTNESS of magnitude assignment:
  P->N edge: topo_pos[P] < topo_pos[N] -> v_P > v_N -> a_P + a_N > 0 >= 0 (o=1
strict OK) N->P edge: topo_pos[N] < topo_pos[P] -> v_N > v_P -> a_P + a_N < 0
(o=2 OK) PP+o=1: a_P + a_Q = v_P + v_Q >= 2 > 0 (always OK) NN+o=2: a_N + a_M =
-(v_N + v_M) <= -2 < 0 (always OK)
*/
