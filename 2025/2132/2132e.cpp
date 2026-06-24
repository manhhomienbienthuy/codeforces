/*!
 * author: manhhomienbienthuy
 * created: 2026-06-23T06:42:46+00:00
 * https://codeforces.com/contest/2132/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<int> a(n), b(m);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        sort(a.begin(), a.end(), greater<>());
        sort(b.begin(), b.end(), greater<>());

        vector<int64_t> pa(n + 1, 0), pb(m + 1, 0);
        for (int i = 0; i < n; i++) pa[i + 1] = pa[i] + a[i];
        for (int i = 0; i < m; i++) pb[i + 1] = pb[i] + b[i];

        while (q--) {
            int x, y, z;
            cin >> x >> y >> z;

            int l = max(0, z - y);
            int r = min(z, x);

            if (l > r) {
                cout << 0 << "\n";
                continue;
            }

            auto f = [&](int k) { return pa[k] + pb[z - k]; };

            while (r - l > 3) {
                int m1 = l + (r - l) / 3;
                int m2 = r - (r - l) / 3;

                if (f(m1) < f(m2))
                    l = m1;
                else
                    r = m2;
            }

            int64_t ans = 0;
            for (int k = l; k <= r; k++) ans = max(ans, f(k));
            cout << ans << "\n";
        }
    }

    return 0;
}
