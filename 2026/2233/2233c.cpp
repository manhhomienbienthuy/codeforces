#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        vector<int> ans(n, 0);
        int l, cur = 0;
        bool flag;
        while (k > 0) {
            l = 0;
            flag = true;
            for (int i = cur; i < n && k > 0; i++) {
                l += (s[i] == '(') - (s[i] == ')');
                if (l < 0) {
                    flag = false;
                    for (int j = i - 1; j >= cur && k > 0; j--) {
                        if (s[j] == '(') {
                            k--;
                            ans[j] = 1;
                        }
                    }
                    cur = i + 1;
                    break;
                }
            }

            if (flag) break;
        }

        cur = n - 1;
        while (k > 0) {
            l = 0;
            flag = true;
            for (int i = cur; i >= 0 && k > 0; i--) {
                l += (s[i] == ')') - (s[i] == '(');
                if (l < 0) {
                    flag = false;
                    for (int j = i + 1; j <= cur && k > 0; j++) {
                        if (s[j] == ')') {
                            k--;
                            ans[j] = 1;
                        }
                    }
                    cur = i - 1;
                    break;
                }
            }

            if (flag) break;
        }

        for (int i = 0; i < n && k > 0; i++) {
            if (!ans[i] && s[i] == '(') {
                k--;
                ans[i] = 1;
            }
        }

        for (int x : ans) cout << x;
        cout << '\n';
    }

    return 0;
}
