/*!
 * author: manhhomienbienthuy
 * created: 2026-06-18T15:44:47+00:00
 * https://codeforces.com/contest/2237/problem/D
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

        vector<int64_t> cnt(3, 0);
        cnt[0] = 1;
        int64_t ans = 0;
        int p = 0;
        int alt = 1;

        for (int i = 0; i < n; i++) {
            p += (s[i] == '1') - (s[i] == '0');
            int val = (p % 3 + 3) % 3;
            ans += i + 1 - cnt[val];
            cnt[val]++;
            if (i > 0 && s[i] != s[i - 1])
                alt++;
            else
                alt = 1;
            ans -= (alt - 1) / 2;
        }

        cout << ans << "\n";
    }
}
