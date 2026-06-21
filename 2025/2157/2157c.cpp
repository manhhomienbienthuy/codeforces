#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n);
        while (q--) {
            int c, l, r;
            cin >> c >> l >> r;
            l--; r--;
            // a[i] = 1 if min 2 if mex 3 if both
            if (c == 1) {
                for (int i = l; i <= r; i++) {
                    if (a[i] == 1 || a[i] == 3) continue;
                    a[i] += 1;
                }
            } else {
                for (int i = l; i <= r; i++) {
                    if (a[i] == 2 || a[i] == 3) continue;
                    a[i] += 2;
                }
            }
        }

        int need = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) a[i] = k;
            else if (a[i] == 3) a[i] = k + 1;
            else if (a[i] == 2) a[i] = (need++ % k);
            else a[i] = 1;
        }

        for (auto x : a) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
