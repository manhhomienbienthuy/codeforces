#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool good(const vector<ll>& a, ll n)
{
    vector<bool> used(n, false);
    used[a[0]] = true;

    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            if (used[a[i]]) return false;
            used[a[i]] = true;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        vector<ll> b = a;
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        for (int i = 0; i < n; i++) {
            a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        }

        if (good(a, n)) {
            cout << "YES\n";
            continue;
        }

        vector<vector<ll>> segs(n);
        vector<ll> cnt(n, 0);
        ll x = a[0];
        cnt[x] = 1;
        segs[x].push_back(0);
        for (ll i = 1; i < n; i++) {
            if (a[i] != x) {
                segs[x].push_back(i - 1);
                segs[x].push_back(i);
                x = a[i];
                segs[x].push_back(i - 1);
                segs[x].push_back(i);
                cnt[x]++;
            }
        }
        segs[x].push_back(n - 1);

        bool ok = false;
        for (auto x : a) {
            if (cnt[x] > 1) {
                if (cnt[x] > 3) break;
                segs[x].erase(unique(segs[x].begin(), segs[x].end()), segs[x].end());
                for (ll i : segs[x]) {
                    for (ll j : segs[x]) {
                        if (i >= j) continue;
                        swap(a[i], a[j]);
                        if (good(a, n)) ok = true;
                        swap(a[i], a[j]);
                        if (ok) break;
                    }
                    if (ok) break;
                }
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}
