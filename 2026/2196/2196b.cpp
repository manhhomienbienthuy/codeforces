#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    uint32_t t;
    cin >> t;

    while (t--) {
        uint32_t n;
        cin >> n;

        vector<uint32_t> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        uint32_t b = (int)sqrt(n);
        uint32_t ans = 0;

        for (int i = 0; i < n; i++) {
            uint32_t x = a[i];
            if (x >= n) continue;
            if (x > b) {
                for (int k = 1; k <= (n - 1 - i) / x; k++) {
                    long j = i + x * k;
                    if (a[j] == k) ans++;
                }
                for (int k = 1; k <= i / x; k++) {
                    long j = i - x * k;
                    if (a[j] == k) ans++;
                }
            } else {
                for (int k = 1; k <= (n - 1 - i) / x && k <= b; k++) {
                    int j = i + x * k;
                    if (a[j] == k) ans++;
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
