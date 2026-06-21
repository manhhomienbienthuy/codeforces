/*!
 * author: manhhomienbienthuy
 * created: 2026-06-18T06:19:58+00:00
 * https://codeforces.com/contest/2169/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, a, l = 0;
        cin >> n >> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            l += (x > a) - (x < a);
        }
        cout << (a - 1 + 2 * (l >= 0)) << "\n";
    }

    return 0;
}
