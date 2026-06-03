#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> mx(n + 1), parent(n + 1);

        stack<tuple<int,int,int>> st;
        st.push({n, -1, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.top();
            st.pop();

            if (state == 0) {
                st.push({u, p, 1});
                for (int v : g[u]) {
                    if (v == p) continue;
                    parent[v] = u;
                    st.push({v, u, 0});
                }
            } else {
                mx[u] = u;
                for (int v : g[u]) {
                    if (v == p) continue;
                    mx[u] = max(mx[u], mx[v]);
                }
            }
        }

        vector<int> mx2(n + 1, 0);
        for (int u = 1; u <= n; u++) {
            int m = 0;
            for (int v : g[u]) {
                if (v != parent[u]) {
                    m = max(m, mx[v]);
                }
            }
            mx2[u] = m;
        }

        vector<bool> ok(n + 1, false);
        ok[n] = true;

        for (int v : g[n]) {
            if (mx[v] < n - 1)
                continue;

            stack<pair<int,int>> st2;
            st2.push({v, n});

            while (!st2.empty()) {
                auto [u, p] = st2.top();
                st2.pop();
                ok[u] = true;

                for (int to : g[u]) {
                    if (to == p) continue;
                    st2.push({to, u});
                }
            }
            bool flag = false;
            for (int i = n - 1; i >= 0; i--) {
                if (!flag && !ok[i]) flag = true;
                if (flag && ok[i]) ok[i] = false;
            }
        }

        vector<ll> dp(n + 1, 0), pref(n + 1, 0);

        int idx = -1;
        for (int i = n; i >= 1; i--) {
            if (g[i].size() == 1) {
                idx = i;
                break;
            }
        }

        dp[idx] = 1;
        pref[idx] = 1;

        for (int i = idx + 1; i <= n; i++) {
            int l = mx2[i];
            if (l + 1 < i) {
                dp[i] = (pref[i - 1] - pref[l] + MOD) % MOD;
            }
            pref[i] = (pref[i - 1] + dp[i]) % MOD;
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (ok[i]) {
                ans = (ans + dp[i]) % MOD;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
