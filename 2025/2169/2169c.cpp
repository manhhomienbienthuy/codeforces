/*!
 * author: manhhomienbienthuy
 * created: 2026-06-18T08:04:49+00:00
 * https://codeforces.com/contest/2169/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int64_t ans = 0, pref = 0, d = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ans += x;
            pref = max(pref + 2 * (i + 1) - x, 0ll + 2 * (i + 1) - x);
            d = max(d, pref);
        }
        cout << ans + d << "\n";
    }

    return 0;
}
