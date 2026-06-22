/*!
 * author: manhhomienbienthuy
 * created: 2026-06-22T01:42:51+00:00
 * https://codeforces.com/contest/2176/problem/C
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
        vector<int> odd, even;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x & 1)
                odd.push_back(x);
            else
                even.push_back(x);
        }

        if (!odd.size()) {
            for (int i = 0; i < n; i++) cout << "0 ";
            cout << "\n";
            continue;
        }

        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        vector<int64_t> ans(n);
        vector<int> used;
        ans[0] = odd.back();
        odd.pop_back();
        for (int i = 1; i < n; i++) {
            if (ans[i - 1] == 0) {
                if (odd.size()) {
                    ans[i] = ans[0];
                    odd.pop_back();
                } else
                    ans[i] = 0;
                continue;
            }
            if (even.size()) {
                ans[i] = ans[i - 1] + even.back();
                used.push_back(even.back());
                even.pop_back();
                continue;
            }
            if (odd.size() > 1 && used.size()) {
                odd.pop_back();
                odd.pop_back();
                ans[i] = ans[i - 1] - used.back();
                even.push_back(used.back());
                used.pop_back();
            } else {
                ans[i] = 0;
                odd.pop_back();
            }
        }

        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
