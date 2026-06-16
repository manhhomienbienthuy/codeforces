/*!
 * author: manhhomienbienthuy
 * created: 2026-06-15T05:54:05+00:00
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
        int n;
        cin >> n;
        vector<tuple<int, int, int>> a(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            a[i] = {x, y, i + 1};
        }
        sort(a.begin(), a.end());
        vector<tuple<int, int, int>> b(n/2), c(n/2);
        for (int i = 0; i < n/2; i++) {
            c[i] = a[i];
            b[i] = a[i + n/2];
        }
        sort(c.begin(), c.end(), [](auto &x, auto &y) {
            return get<1>(x) < get<1>(y);
        });
        sort(b.begin(), b.end(), [](auto &x, auto &y) {
            return get<1>(x) > get<1>(y);
        });
        for (int i = 0; i < n/2; i++){
            cout << get<2>(c[i]) << " " << get<2>(b[i]) << "\n";
        }
    }

    return 0;
}
