/*!
 * author: manhhomienbienthuy
 * created: 2026-06-18T15:36:58+00:00
 * https://codeforces.com/contest/2237/problem/B
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
        vector<int> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;

        int64_t ans = 0;
        for (int i = 0; i < n; i++) {
            bool ok = false;
            for (int j = i; j < n; j++) {
                if (a[j] <= b[i]) {
                    ok = true;
                    rotate(a.begin() + i, a.begin() + j, a.begin() + j + 1);
                    ans += j - i;
                    break;
                }
            }
            if (!ok) {
                ans = -1;
                break;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
