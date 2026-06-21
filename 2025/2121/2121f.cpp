#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct FastHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll s, x;
        cin >> n >> s >> x;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll ans = 0;

        unordered_map<ll, ll, FastHash> before;
        vector<ll>after;
        after.push_back(0);

        ll pref = 0;

        for (auto v : a) {
            if (v > x) {
                before.clear();
                after.clear();
                after.push_back(0);
                pref = 0;
                continue;
            }

            if (v == x) {
                for (auto p : after) {
                    before[p]++;
                }
                after.clear();
            }

            pref += v;
            after.push_back(pref);
            if (before.count(pref - s)) {
                ans += before[pref - s];
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
