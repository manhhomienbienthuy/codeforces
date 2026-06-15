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
        vector<int> d(k, 0);
        for (int i = 0; i < n; i++) d[i % k] ^= (s[i] == '1');
        bool ok = true;
        for (int i = 0; i < k; i++) {
            if (d[i]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
