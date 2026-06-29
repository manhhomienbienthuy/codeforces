#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// power of 2
int64_t power(int64_t p) {
  if (p < 30) return (1 << p) % MOD;
  int64_t r = power(p / 2);
  return (r * r * (1 << (p & 1))) % MOD;
}

// power of a
int64_t power(int64_t a, int64_t p) {
  int64_t r = 1;
  while (p > 0) {
    if (p & 1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    p >>= 1;
  }
  return r;
}

// get MSB
int64_t setBitNumber(int64_t n) {
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n |= n >> 32;
  n = (n >> 1) + 1;
  return n;
}

const int MAX = 510000;
int64_t fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void fact_init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto& x : a) cin >> x;

    int64_t ans = 1e18;
    int i = 0;
    while (i < n) {
      int j = i;
      while (j < n && a[i] == a[j]) j++;
      ans = min(ans, a[i] * (n - j + i));
      i = j;
    }

    cout << ans << '\n';
  }

  return 0;
}
