/*!
 * author: manhhomienbienthuy
 * created: 2026-11-21T16:18:49+00:00
 * https://codeforces.com/contest/2287/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int ROOT = 3;

int pw(int64_t a, int64_t p, int64_t m = MOD) {
  int64_t r = 1;

  for (a %= m; p > 0; p >>= 1, a = a * a % m) {
    if (p & 1) r = r * a % m;
  }

  return (int)r;
}

void ntt(vector<int>& a, bool inv) {
  int n = (int)a.size();

  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;

    while (j & bit) {
      j ^= bit;
      bit >>= 1;
    }

    j ^= bit;

    if (i < j) swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    int wlen = pw(ROOT, (MOD - 1) / len);

    if (inv) wlen = pw(wlen, MOD - 2);

    int half = len >> 1;

    for (int i = 0; i < n; i += len) {
      int64_t w = 1;

      for (int j = 0; j < half; j++) {
        int u = a[i + j];
        int v = (int)(a[i + j + half] * w % MOD);

        a[i + j] = u + v;
        if (a[i + j] >= MOD) a[i + j] -= MOD;

        a[i + j + half] = u - v;
        if (a[i + j + half] < 0) a[i + j + half] += MOD;

        w = w * wlen % MOD;
      }
    }
  }

  if (inv) {
    int inv_n = pw(n, MOD - 2);

    for (int& x : a) {
      x = (int)((int64_t)x * inv_n % MOD);
    }
  }
}

uint64_t rng_() {
  static uint64_t x = chrono::steady_clock::now().time_since_epoch().count();

  x += 0x9e3779b97f4a7c15ULL;

  uint64_t z = x;
  z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
  z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;

  return z ^ (z >> 31);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;

    cin >> n >> s;

    vector<int> p(n), w(n);

    for (int& x : p) {
      cin >> x;
      x--;
    }

    for (int& x : w) {
      x = (int)(rng_() % (MOD - 1)) + 1;
    }

    int sz = 1;
    while (sz < 2 * n) sz <<= 1;

    vector<int> fa(sz);

    for (int i = 0; i < n; i++) {
      fa[i] = s[i] - 'a' + 1;
    }

    ntt(fa, false);

    auto check = [&](int len) {
      if (len == 0) return true;

      vector<int> fb(sz);

      for (int i = 0; i < len; i++) {
        fb[n - 1 - p[i]] = w[i];
      }

      ntt(fb, false);

      for (int i = 0; i < sz; i++) {
        fb[i] = (int)((int64_t)fa[i] * fb[i] % MOD);
      }

      ntt(fb, true);

      vector<int> hs(n);

      for (int k = 0; k < n; k++) {
        int h = fb[k + n - 1];

        if (k > 0) {
          h += fb[k - 1];
          if (h >= MOD) h -= MOD;
        }

        hs[k] = h;
      }

      sort(hs.begin(), hs.end());

      for (int i = 1; i < n; i++) {
        if (hs[i] == hs[i - 1]) return true;
      }

      return false;
    };

    int lo = 0, hi = n;

    while (lo <= hi) {
      int mid = (lo + hi + 1) >> 1;

      if (check(mid))
        lo = mid + 1;
      else
        hi = mid - 1;
    }

    cout << hi << '\n';
  }

  return 0;
}
