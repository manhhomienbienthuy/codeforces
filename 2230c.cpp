/*!
 * author: manhhomienbienthuy
 * created: 2026-06-17T03:11:07+00:00
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
        uint64_t ans = 0;
        uint64_t one = 0;
        uint64_t ext = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 1)
                one++;
            else {
                ans += x;
                ext += x / 2 - 1;
            }
        }
        if (n == 1) {
            cout << (ans >= 3 ? ans : 0) << "\n";
        } else {
            ext += one == n - 1;
            cout << ans + min(one, ext) << "\n";
        }
    }

    return 0;
}
