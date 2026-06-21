#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll setBitNumber(ll n)
{
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;
    n = ((n + 1) >> 1) | (n & (1 << ((sizeof(n) * CHAR_BIT) - 1)));
    return n;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto & x: a) cin >> x;


        ll ans = 1e18;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && a[i] == a[j]) j++;
            ans = min(ans, a[i] * (n - j + i));
            i = j;
        }

        cout << ans << '\n';
    }

    return 0;
}
