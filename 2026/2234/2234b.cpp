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

        if (n == 10) {
            cout << "-1\n";
            continue;
        }

        ll r = n % 12;
        if (r == 10) r = 22;
        cout << r << ' ' << n - r << '\n';
    }

    return 0;
}
