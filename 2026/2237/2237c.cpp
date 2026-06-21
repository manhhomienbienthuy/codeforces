/*!
 * author: manhhomienbienthuy
 * created: 2026-06-18T15:30:14+00:00
 * https://codeforces.com/contest/2237/problem/C
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
        int64_t m = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (m > x)
                m = m + x;
            else
                m = x;
        }

        cout << m << "\n";
    }

    return 0;
}
