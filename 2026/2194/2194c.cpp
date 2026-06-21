/*!
 * author: manhhomienbienthuy
 * created: 2026-06-15T09:26:36+00:00
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> msk(n, 0);
        for (int i = 0; i < k; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                msk[j] |= 1 << (s[j] - 'a');
            }
        }
        for (int d = 1; d <= n; d++) {
            if (n % d) continue;
            bool ok = true;
            string ans = "";
            for (int j = 0; j < d; j++) {
                int m = (1 << 26) - 1;
                for (int u = j; u < n; u += d) {
                    m &= msk[u];
                    if (!m) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
                char u = 'a';
                while (!(1 & (m >> (u++ - 'a'))));
                ans += u - 1;
            }

            if (ok) {
                int u = n / d;
                while (u--) cout << ans;
                cout << "\n";
                break;
            }
        }
    }

    return 0;
}
