/*!
 * author: manhhomienbienthuy
 * created: 2026-07-24T06:35:09+00:00
 * https://codeforces.com/contest/2224/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

struct Frac {
  int num;
  int den;
};

int64_t power(int64_t a, int64_t p) {
  int64_t r = 1;
  while (p) {
    if (p & 1) r = r * a % MOD;
    a = a * a % MOD;
    p >>= 1;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    vector<Frac> fb;
    fb.reserve(1LL * n * (n - 1));

    for (int p = 0; p < n; p++) {
      for (int q = 0; q < n; q++) {
        if (p != q) fb.push_back({b[q], b[p]});
      }
    }

    sort(fb.begin(), fb.end(), [&](const Frac& a, const Frac& b) {
      return 1LL * a.num * b.den < 1LL * b.num * a.den;
    });

    int64_t s = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int cnt =
            (int)(lower_bound(fb.begin(), fb.end(), 0,
                              [&](const Frac& f, int) {
                                return 1LL * f.num * a[j] < 1LL * f.den * a[i];
                              }) -
                  fb.begin());
        s += cnt;
      }
    }

    int64_t den = 1LL * n * (n - 1) % MOD;
    int64_t ans = s % MOD * power(den, MOD - 2) % MOD;

    cout << ans << '\n';
  }

  return 0;
}
