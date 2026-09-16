/*!
 * author: manhhomienbienthuy
 * created: 2026-09-15T05:22:45+00:00
 * https://codeforces.com/contest/2264/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

const int MAX = 2e5 + 5;
int64_t fac[MAX], inv_[MAX];

void fact_init() {
  fac[0] = fac[1] = 1;
  inv_[1] = 1;

  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv_[i] = MOD - inv_[MOD % i] * (MOD / i) % MOD;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fact_init();

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int64_t> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }

    vector<int64_t> suf(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) suf[i] = (suf[i + 1] + a[i]) % MOD;

    int64_t tot = 0;
    for (int k = 0; k < n - 1; k++)
      tot = (tot + suf[k + 1] % MOD * inv_[n - 1 - k]) % MOD;

    int64_t s = suf[0];
    int64_t sub = ((s - a[n - 1]) % MOD + MOD) % MOD;

    int64_t ans = fac[n - 1] % MOD * ((tot - sub) % MOD + MOD) % MOD;
    cout << ans << '\n';
  }

  return 0;
}
