/*!
 * author: manhhomienbienthuy
 * created: 2026-06-15T10:38:59+00:00
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> pref(n, vector<int>(m + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                if (!j) pref[i][j] = x;
                else pref[i][j] = pref[i][j - 1] + x;
            }
            if (i == 0) pref[i][m] = pref[i][m - 1];
            else pref[i][m] = pref[i - 1][m] + pref[i][m - 1];
        }
        int row, col;
        int h = pref[n - 1][m] / 2;
        for (row = 0; row < n && pref[row][m] <= h; row++);
        if (row < n)
            for (col = 0; col < m && pref[row][m] - pref[row][col] > h; col++);
        else
            col = 0;
        cout << 1ll * h * (pref[n - 1][m] - h) << "\n";
        for (int i = 0; i < row; i++) cout << "D";
        for (int i = 0; i <= col; i++) cout << "R";
        if (row < n) cout << "D";
        for (int i = col + 1; i < m; i++) cout << "R";
        for (int i = row + 1; i < n; i++) cout << "D";
        cout << "\n";
    }

    return 0;
}
