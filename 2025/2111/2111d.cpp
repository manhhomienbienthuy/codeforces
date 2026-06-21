#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(m);
        for (int i = 0; i < m; i++) cin >> a[i];
        sort(a.begin(), a.end());

        for (int i = 0; i < n / 2; i++) {
            for (int k = 0; k < 3; k++) {
                cout << a[i] << ' ';
                cout << a[m - i - 1] << ' ';

            }
            cout << '\n';
            for (int k = 0; k < 3; k++) {
                cout << a[m - i - 1] << ' ';
                cout << a[i] << ' ';

            }
            cout << '\n';
        }
        if (n & 1) {
            int i = n / 2;
            for (int k = 0; k < 3; k++) {
                cout << a[i] << ' ';
                cout << a[m - i - 1] << ' ';

            }
            cout << '\n';
        }
    }

    return 0;
}
