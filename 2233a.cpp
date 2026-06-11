#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x, y, z;
        cin >> n >> x >> y >> z;
        int ans = (n + x + y - 1) / (x + y);
        ans = min(ans, (n + x - 1) / x);
        if (x * z < n) {
            ans = min(ans, z + (n - x * z + x + 10 * y - 1) / (x + 10 * y));
        }
        cout << ans << '\n';
    }

    return 0;
}
