#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        int B = max(1, (int)sqrt((double)n));
        long long ans = 0;

        // Case 1: a[i] <= sqrt(n)
        // For each small value v, for each j, check if i = j - v*a[j] is valid
        for (int v = 1; v <= B; v++) {
            for (int j = 1; j <= n; j++) {
                long long ci = (long long)j - (long long)v * a[j];
                if (ci >= 1 && ci < j && a[(int)ci] == v) {
                    ans++;
                }
            }
        }

        // Case 2: a[i] > sqrt(n), a[j] <= sqrt(n)
        // For each i with large a[i], try each small v as potential a[j]
        for (int i = 1; i <= n; i++) {
            if (a[i] > B) {
                for (int v = 1; v <= B; v++) {
                    long long cj = (long long)i + (long long)a[i] * v;
                    if (cj > n) break;
                    if (a[(int)cj] == v) {
                        ans++;
                    }
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
