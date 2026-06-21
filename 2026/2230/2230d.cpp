/*!
 * author: manhhomienbienthuy
 * created: 2026-06-17T06:25:28+00:00
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<int> dp(n + 2, n);
        int64_t ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == b[i])
                dp[a[i]] = dp[a[i] + 1];
            else
                dp[a[i]] = dp[b[i]] = i;

            ans += dp[1] - i;
        }

        cout << ans << "\n";
    }

    return 0;
}
