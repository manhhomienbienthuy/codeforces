#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        ll cnt_a = 0, cnt_b = 0, cnt_c = 0;
        for (ll i = 0; i < n; i++) {
            cnt_a += (a[i] == '1');
            cnt_b += (b[i] == '1');
            cnt_c += (a[i] != b[i]);
        }
        ll sa = cnt_a * (n - cnt_a),
            sb = cnt_b * (n - cnt_b),
            sc = cnt_c * (n - cnt_c);
        ll l = (1 << k) + 1;
        ll q = l / 3, r = l % 3;
        ll ans = q * (sa + sb + sc) + r / 2 * (sa + sb);
        cout << ans << '\n';
    }

    return 0;
}
