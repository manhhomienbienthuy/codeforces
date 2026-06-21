/*!
 * author: manhhomienbienthuy
 * created: 2026-06-17T03:06:31+00:00
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
        int odd = 0, even = 0;
        for (char c : s) {
            if (c == '2')
                even++;
            else if (c == '1' || c == '3')
                odd = max(odd, even) + 1;
        }
        cout << n - max(odd, even) << "\n";
    }

    return 0;
}
