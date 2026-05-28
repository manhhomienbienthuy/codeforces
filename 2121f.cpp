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

ll calc(const vector<ll>& a, ll s, ll limit) {
    unordered_map<ll, ll, FastHash> cnt;
    cnt[0] = 1;

    ll pref = 0;
    ll res = 0;

    for (ll v : a) {
        if (v > limit) {
            cnt.clear();
            cnt[0] = 1;
            pref = 0;
            continue;
        }

        pref += v;

        auto it = cnt.find(pref - s);
        if (it != cnt.end()) {
            res += it->second;
        }

        cnt[pref]++;
    }

    return res;
}

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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll ans = calc(a, s, x) - calc(a, s, x - 1);
        cout << ans << '\n';
    }

    return 0;
}
