/*!
 * author: manhhomienbienthuy
 * created: 2026-06-22T01:34:53+00:00
 * https://codeforces.com/contest/2176/problem/A
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
        int ans = 0, m = 0;
        while (n--) {
            int x;
            cin >> x;
            if (x < m)
                ans++;
            else
                m = x;
        }
        cout << ans << "\n";
    }

    return 0;
}
