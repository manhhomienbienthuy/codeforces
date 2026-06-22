/*!
 * author: manhhomienbienthuy
 * created: 2026-06-22T01:38:26+00:00
 * https://codeforces.com/contest/2176/problem/B
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
        string s;
        cin >> n >> s;
        while (s.back() == '0') {
            s.pop_back();
            s = '0' + s;
        }
        int cur = s[0] == '0';
        int ans = cur;
        for (int i = 1; i < n; i++) {
            cur += s[i] == '0';
            if (s[i] == '1') {
                ans = max(ans, cur);
                cur = 0;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
