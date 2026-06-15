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
        ll n, l, r;
        cin >> n >> l >> r;
        vector<ll> a(n);
        for (auto & x: a) cin >> x;
        sort(a.begin(), a.end());

        ll ans = 0;
        ll left, right = -1;
        if (n & 1) left = right = n / 2;
        for (ll i = 0; i < n / 2; i++) {
            if (a[i] >= r || a[n - i - 1] <= l) {
                left = i; right = n - i - 1;
                break;
            }
            ans += a[n - i - 1] - a[i];
        }
        for (ll i = left; i <= right; i++) {
            if (a[i] < l) ans += l - a[i];
            else if (a[i] > r) ans += a[i] - r;
        }

        cout << ans << '\n';
    }

    return 0;
}
