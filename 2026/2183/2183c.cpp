#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;

        ll half = min(k - 1, n - k);
        ll ans = min(half, m / 3 + 1);
        if (half > 0) m -= 2 * ans - 1;
        else half = 1;
        if (half >= m) ans += m + 1;
        else ans += 1 + (m - half) / 2 + half;

        cout << min(n, ans) << '\n';
    }

    return 0;
}
