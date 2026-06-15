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
        cin >> n >> k;
        vector<int> a(n);
        for (auto & x : a) cin >> x;
        sort(a.begin(), a.end());

        bool ok = false;
        int i = 0;
        while (i < n) {
            int j = i;
            while (++j < n && a[j] - a[j - 1] <= k);
            if (a[i] != a[j - 1]) {
                ok = true;
                break;
            } else if (!((j - i) & 1)) {
                ok = true;
                break;
            }
            if (ok) break;
            i = j;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
