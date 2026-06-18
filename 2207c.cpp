/*!
 * author: manhhomienbienthuy
 * created: 2026-06-18T02:16:29+00:00
 * https://codeforces.com/contest/2207/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, h;
        cin >> n >> h;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<uint64_t> w(n, 0);
        for (int i = 0; i < n; i++) {
            w[i] = h - a[i];
            int m = a[i];
            for (int j = i - 1; j >= 0; j--) {
                if (a[j] > m) m = a[j];
                w[i] += h - m;
            }
            m = a[i];
            for (int j = i + 1; j < n; j++) {
                if (a[j] > m) m = a[j];
                w[i] += h - m;
            }
        }

        uint64_t ans = w[0];
        for (int i = 0; i < n - 1; i++) {
            int idx = i;
            for (int j = i + 1; j < n; j++) {
                if (a[j] > a[idx]) idx = j;
                ans = max(ans, w[i] + w[j] - w[idx]);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
