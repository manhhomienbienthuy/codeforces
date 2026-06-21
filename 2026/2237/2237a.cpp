/*!
 * author: manhhomienbienthuy
 * created: 2026-06-18T14:36:00+00:00
 * https://codeforces.com/contest/2237/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m = 1001, ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            m = min(m, x);
            ans += m;
        }

        cout << ans << "\n";
    }

    return 0;
}
