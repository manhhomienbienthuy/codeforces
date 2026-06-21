/*!
 * author: manhhomienbienthuy
 * created: 2026-06-18T07:08:15+00:00
 * https://codeforces.com/contest/2169/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }

        if (s.find("**") != string::npos || s.find("*<") != string::npos ||
            s.find(">*") != string::npos || s.find("><") != string::npos) {
            cout << -1 << "\n";
            continue;
        }

        int ans = 0;
        int i = 0;
        for (i = 0; i < n && s[i] != '>'; i++);
        ans = i;
        for (i = n - 1; i >= 0 && s[i] != '<'; i--);
        ans = max(ans, n - i - 1);
        cout << ans << "\n";
    }

    return 0;
}
