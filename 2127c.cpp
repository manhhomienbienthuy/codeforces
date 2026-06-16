/*!
 * author: manhhomienbienthuy
 * created: 2026-06-15T08:11:08+00:00
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
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i].first = x;
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i].second = x;
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) ans += abs(a[i].first - a[i].second);
        vector<pair<int, int>> b = a;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), [](auto &x, auto &y) {
            return x.second < y.second;
        });
        ll m = 1e18;
        for (int i = 0; i < n - 1; i++) {
            ll org = abs(a[i].first - a[i].second) + abs(a[i + 1].first - a[i + 1].second);
            ll s1 = abs(a[i].first - a[i + 1].first) + abs(a[i].second - a[i + 1].second);
            ll s2 = abs(b[i].first - b[i + 1].first) + abs(b[i].second - b[i + 1].second);
            if (s1 > org) {
                m = min(m, s1 - org);
            } else {
                m = 0;
                break;
            }
            if (s2 > org) {
                m = min(m, s2 - org);
            } else {
                m = 0;
                break;
            }
        }
        cout << ans + m << "\n";
    }

    return 0;
}
