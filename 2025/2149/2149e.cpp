#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k, l, r;
        cin >> n >> k >> l >> r;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> vals = a;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        for (int i = 0; i < n; i++) {
            a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
        }

        int m = vals.size();

        vector<int> cnt1(m, 0), cnt2(m, 0);

        int l1 = 0, l2 = 0;
        int d1 = 0, d2 = 0;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int x = a[i];

            if (cnt1[x] == 0) d1++;
            cnt1[x]++;

            if (cnt2[x] == 0) d2++;
            cnt2[x]++;

            while (d1 > k) {
                int y = a[l1];
                cnt1[y]--;
                if (cnt1[y] == 0) d1--;
                l1++;
            }

            while (d2 > k - 1) {
                int y = a[l2];
                cnt2[y]--;
                if (cnt2[y] == 0) d2--;
                l2++;
            }

            int lo  = max(l1, i - r + 1);
            int hi = min(l2 - 1, i - l + 1);

            if (lo <= hi) {
                ans += (hi - lo + 1);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
