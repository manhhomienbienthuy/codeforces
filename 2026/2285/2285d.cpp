/*!
 * author: manhhomienbienthuy
 * created: 2026-11-15T14:57:13+00:00
 * https://codeforces.com/contest/2285/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int64_t fac[MAX], finv[MAX], inv_[MAX];

void fact_init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv_[1] = 1;

  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv_[i] = MOD - inv_[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv_[i] % MOD;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fact_init();

  int t;
  cin >> t;

  while (t--) {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int64_t> pref(n + 1);
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

    int zero = 0;
    int64_t tot = pref[n];

    unordered_map<int64_t, vector<int>> pos;

    for (int i = 1; i < n; i++) {
      int64_t v = pref[i] + pref[n - i] - tot;
      zero += !v;
      pos[v].push_back(i);
    }

    auto count = [&](int val, int lo, int hi) {
      const auto& p = pos[val];
      return int(upper_bound(p.begin(), p.end(), hi) -
                 lower_bound(p.begin(), p.end(), lo));
    };

    while (q--) {
      int i, v;
      cin >> i >> v;

      int lo = n - i + 1, hi = i - 1;

      if (i <= n - i) {
        lo = i;
        hi = n - i;
        v = -v;
      }

      int64_t z = zero;
      if (lo <= hi) {
        z += count(v, lo, hi) - count(0, lo, hi);
      }

      int64_t ans = 0;
      if (z >= m - 1) {
        ans = fac[z] * finv[m - 1] % MOD * finv[z - m + 1] % MOD;
      }

      cout << ans << '\n';
    }
  }
  return 0;
}
