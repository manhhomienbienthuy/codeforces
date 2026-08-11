/*!
 * author: manhhomienbienthuy
 * created: 2026-08-10T08:44:34+00:00
 * https://codeforces.com/contest/2256/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

const int MAX = 1e6 + 5;

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

int64_t C(int n, int r) {
  if (r <= 0 || r >= n) {
    return 1;
  }

  return fac[n] * finv[r] % MOD * finv[n - r] % MOD;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fact_init();

  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;

    cin >> n >> s;

    vector<int> cnt(2, 0), segs(2, 0);

    for (int i = 0, j; i < n; i = j) {
      for (j = i; j < n && s[j] == s[i]; j++);
      segs[s[i] - '0']++;
      cnt[s[i] - '0'] += j - i;
    }

    int64_t ans = 1;

    for (int i = 0; i < 2; i++) ans = ans * C(cnt[i] - 1, segs[i] - 1) % MOD;

    cout << ans << '\n';
  }

  return 0;
}
