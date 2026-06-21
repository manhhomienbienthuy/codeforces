#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        vector<ll> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        vector<ll> min_a(n), max_a(n), min_b(n), max_b(n);
        min_a[0] = max_a[0] = a[0];
        min_b[n - 1] = max_b[n - 1] = b[n - 1];
        for (ll i = 1; i < n; i++) {
            min_a[i] = min(min_a[i - 1], a[i]);
            max_a[i] = max(max_a[i - 1], a[i]);
            min_b[n - i - 1] = min(min_b[n - i], b[n - i - 1]);
            max_b[n - i - 1] = max(max_b[n - i], b[n - i - 1]);
        }

        vector<pair<ll, ll>> segs(n);
        for (int i = 0; i < n; i++) {
            segs[i] = {min(min_a[i], min_b[i]), max(max_a[i], max_b[i])};
        }
        segs.erase(unique(segs.begin(), segs.end()), segs.end());
        sort(segs.begin(), segs.end(), [](auto &a, auto &b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });

        ll l = segs[0].first, r = segs[0].second;
        ll ans = l * (2 * n - r + 1);
        for (ll i = 1; i < segs.size(); i++) {
            l = segs[i].first;
            ll rr = segs[i].second;
            if (rr < r) {
                ans += (r - rr) * l;
            }
            r = min(r, rr);
        }

        cout << ans << '\n';
    }

    return 0;
}
