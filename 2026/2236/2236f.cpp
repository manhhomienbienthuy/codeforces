#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;
const int N = 5e5 + 2;
int spf[N];

void init() {
    for (int i = 2; i < N; i++) {
        if (!spf[i]) {
            spf[i] = i;
            for (ll j = 1LL * i * i; j < N; j += i)
                if (!spf[j]) spf[j] = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    vector<int> cnt(N);

    int t;
    cin >> t;

    while (t--) {
        int n, a;
        cin >> n >> a;

        ll ans = 1;
        vector<int> used;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            while (x > 1) {
                int p = spf[x];
                int c = 0;

                while (x % p == 0) {
                    x /= p;
                    c++;
                }

                if (cnt[p] == 0) used.push_back(p);
                cnt[p] += c;
            }
        }

        for (int p : used) {
            ans = (ans * (cnt[p] + 1)) % mod;
            cnt[p] = 0;
        }

        cout << ans << '\n';
    }

    return 0;
}
