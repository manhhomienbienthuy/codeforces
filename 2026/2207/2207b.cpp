/*!
 * author: manhhomienbienthuy
 * created: 2026-06-17T15:08:36+00:00
 * https://codeforces.com/contest/2207/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, l;
        cin >> n >> m >> l;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int len = min(n + 1, m);
        vector<int> d(len, 0);
        for (int i = 1; i <= l; i++) {
            d[0]++;
            sort(d.begin(), d.end());
            for (auto x : a) {
                if (x == i) {
                    if (len > n--) {
                        d.pop_back();
                        len--;
                        break;
                    } else {
                        d[len - 1] = 0;
                        sort(d.begin(), d.end());
                        break;
                    }
                }
            }
        }

        cout << d[len - 1] << "\n";
    }

    return 0;
}
