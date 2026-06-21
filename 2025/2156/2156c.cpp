#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        vector<int>pref(n + 1, 0);
        for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + cnt[i];

        bool found = false;
        for (int i = n; i > 1; i--) {
            int s = pref[min(n, 4 * i - 1)] - cnt[i];
            if (2 * i <= n) s -= cnt[2 * i];
            if (3 * i <= n) s -= cnt[3 * i];
            if (s <= k) {
                cout << i << "\n";
                found = true;
                break;
            }
        }

        if (!found) cout << 1 << "\n";
    }

    return 0;
}
