/*!
 * author: manhhomienbienthuy
 * created: 2026-06-22T07:11:14+00:00
 * https://codeforces.com/contest/2176/problem/D
 */

/*
Problem D - Generalized Fibonacci Paths

=== Problem Summary ===
Directed graph with n vertices, each vertex v has value a[v] > 0.
Count simple paths of length >= 2 whose vertex values form a generalized
Fibonacci sequence. Generalized Fibonacci: x0, x1 arbitrary natural numbers; xi
= xi-2 + xi-1 for i >= 2.

=== Key Observation 1: Paths are automatically simple ===
For a valid Fibonacci path v1, v2, ..., vk (k >= 3):
- a[v3] = a[v1]+a[v2] > a[v1] and > a[v2]  (since all values >= 1)
- a[v4] = a[v2]+a[v3] > a[v3] > a[v2] and > a[v1]
- Sequence a[v3], a[v4], ..., a[vk] is STRICTLY INCREASING
- Therefore: vertices at positions >= 3 are all distinct (different values ->
different vertices)
- Vertices at positions >= 3 are different from v1, v2 (their values are larger)
- v1 != v2 is guaranteed since edge (v1, v2) exists and no self-loops

=> ANY Fibonacci path in this directed graph is automatically a simple path.

=== Key Observation 2: Path length is bounded ===
Starting with a[v1]=1, a[v2]=1 (minimum values), the sequence grows like
Fibonacci numbers. Fibonacci F(87) ~ 6.8e17, F(88) ~ 1.1e18. So any valid
Fibonacci path has at most ~87 vertices.

=== DP Formulation ===
For each directed edge (u, v), define:
 dp[(u,v)] = number of valid Fibonacci paths that END with edge (u -> v)

Base case: dp[(u,v)] = 1 for every edge (the 2-vertex path u->v)

Transition: dp[(u,v)] += dp[(w,u)] for all in-edges (w,u) where a[w] = a[v] -
a[u] (i.e., the path ...->w->u->v satisfies a[v] = a[w] + a[u])

Dependency order: dp[(u,v)] depends on dp[(w,u)] where a[u] < a[v] (since a[w] =
a[v]-a[u] >= 1 requires a[v] > a[u]). So if we process edges in INCREASING order
of a[second_vertex], all dependencies are resolved.

=== Efficient Data Structure ===
For each vertex u, maintain:
 inc[u][x] = sum of dp[(w,u)] over all in-edges (w,u) with a[w] = x

Processing edge (u, v) in order of a[v]:
 need = a[v] - a[u]
 dp = 1 + (inc[u][need] if need >= 1 else 0)
 ans += dp (mod MOD)
 inc[v][a[u]] += dp (mod MOD)

=== Correctness of Level Processing ===
When processing edges at the same level X = a[v]:
- Edge (u,v) at level X uses inc[u][X - a[u]] where a[u] < X (for extension)
- inc[u] is updated by edges (w,u) at level a[u] < X (already processed)
- Updates to inc[v] at level X don't affect other level-X edges
 (because edge (v,w) at level X would need X - a[v] = X - X = 0, no extension)

=== Complexity ===
- Sort edges: O(m log m)
- DP: O(m) total insertions/lookups in hash maps
- Total: O(m log m) per test case, O(sum_m * log(sum_m)) overall

=== Answer ===
answer = sum of all dp[(u,v)] over all edges, modulo 998244353
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int64_t> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<tuple<int64_t, int, int>> edges(m);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edges[i] = {a[v], u, v};
        }
        sort(edges.begin(), edges.end());

        vector<unordered_map<int64_t, int64_t>> dp(n + 1);
        int64_t ans = 0;
        for (auto& [av, u, v] : edges) {
            int64_t need = av - a[u];
            int64_t cur = 1;
            if (need >= 1) {
                auto it = dp[u].find(need);
                if (it != dp[u].end()) cur = (cur + it->second) % MOD;
            }
            ans = (ans + cur) % MOD;
            dp[v][a[u]] = (dp[v][a[u]] + cur) % MOD;
        }

        cout << ans << "\n";
    }

    return 0;
}
