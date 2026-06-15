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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        vector<bool> used(n + 1);
        for (int i = 0; i < n; i++) used[a[i]] = true;

        vector<ll> choices(3);
        int ii = 0;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                choices[ii++] = i;
                if (ii == 3) break;
            }
        }

        if (ii == 0) {
            choices = {a[0], a[1], a[2]};
        } else if (ii == 1) {
            choices[2] = a[n - 1];
            for (ll i = 1; i <= n; i++) {
                if (i != choices[0] && i != choices[2]) {
                    choices[1] = i;
                    break;
                }
            }
        } else if (ii == 2) {
            choices[2] = a[n - 1];
        }

        for (ll i = 0; i < k; i++) cout << choices[i % 3] << ' ';
        cout << '\n';
    }

    return 0;
}
