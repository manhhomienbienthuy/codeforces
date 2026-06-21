#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int a, b, x;
        cin >> a >> b >> x;
        int ans = 1e18, s = 0;
        while (a != b) {
            ans = min(ans, s + abs(a - b));
            s++;
            if (a > b) a /= x;
            else b /= x;
        }
        cout << min(ans, s) << '\n';
    }

    return 0;
}
