#include <bits/stdc++.h>
using namespace std;

static const long long INF = (long long)1e18;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        vector<long long> dp(n + 1, INF);

        for (int x : a) {
            dp[x] = 1;
        }
        if (n >= 4) {
            for (int i = 4; i <= n; i++) {
                if (dp[i] == 1) continue;

                int sq = (int)std::sqrt(i);
                for (int x : a) {
                    if (x == 1) continue;
                    if (x > sq) break;
                    if (i % x == 0) {
                        dp[i] = min(dp[i], 1 + dp[i / x]);
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << (dp[i] == INF ? -1 : dp[i]) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
