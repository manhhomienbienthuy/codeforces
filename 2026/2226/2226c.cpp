#include <bits/stdc++.h>
using namespace std;

bool check(const vector<int>& a, int k) {
    multiset<int> ms(a.begin(), a.end());

    for (int x = k - 1; x >= 0; --x) {
        auto it = ms.find(x);
        if (it != ms.end()) {
            ms.erase(it);
            continue;
        }

        int mx = *ms.rbegin();
        if (mx < 2 * x + 1) {
            return false;
        }
        ms.erase(prev(ms.end()));
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        sort(a.begin(), a.end());

        int l = 0, r = n + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (check(a, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }

        cout << l << '\n';
    }
    return 0;
}
