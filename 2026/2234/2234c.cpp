#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        vector<ll> h(n);
        for (ll i = 0; i < n; i++) cin >> h[i];

        vector<ll> w(n);
        for (ll l = 0; l < n; l++) {
            ll s = 0;
            w[l] = 0;
            for (ll i = l + 1; i < l + n; i++) {
                w[i % n] = max(w[(i - 1) % n], h[(i - 1) % n]);
                s += w[i % n];
            }
            for (ll i = l + n - 1; i > l; i--) {
                ll old = w[i % n];
                if (max(w[i % n], w[(i + 1) % n]) > h[i % n] && w[i % n] != w[(i + 1) % n]) {
                    w[i % n] = max(w[(i + 1) % n], h[i % n]);
                    s += w[i % n] - old;
                } else break;
            }

            cout << s << ' ';
        }
        cout << '\n';
    }

    return 0;
}
