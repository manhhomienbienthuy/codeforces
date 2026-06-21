#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x: a) cin >> x;

        vector<vector<bool>> good(n + 1, vector<bool>(n + 1, false));
        for (int i = 0; i < n; i++) {
            vector<bool> used(n + 1, false);
            int mn = 6001, mx = 0;
            for (int j = i; j < n; j++) {
                if (!used[a[j]]) used[a[j]] = true;
                else break;
                mn = min(mn, a[j]);
                mx = max(mx, a[j]);
                if (mx - mn == j - i) {
                    good[mn][mx] = true;
                }
            }
        }

        bool ok = false;
        for (int i = n / 2; i > 0; i--) {
            for (int j = 1; j <= n - 2 * i + 1; j++) {
                if (good[j][j + i - 1] && good[j + i][j + 2 * i - 1]) {
                    cout << i << '\n';
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }

        if (!ok) cout << 0 << '\n';
    }

    return 0;
}
