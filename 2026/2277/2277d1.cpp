/*!
 * author: manhhomienbienthuy
 * created: 2026-10-24T11:55:45+00:00
 * https://codeforces.com/contest/2277/problem/D1
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int64_t f(int64_t n) {
  if (n < 2) return n;

  int64_t sd = 0, sc = 0, ans = LLONG_MAX;

  for (int len = 61; len >= 2; len--) {
    int64_t c = (1LL << len) + len - 1, d = (1LL << len) - 2;

    if (sd + d <= n - 1) {
      sd += d;
      sc += c;
    } else {
      ans = min(ans, sc + c);
    }
  }

  if (sd == n - 1) ans = min(ans, sc);

  return ans - n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int64_t l, r;
    cin >> l >> r;

    int64_t ans = 0;

    for (int64_t i = l; i <= r; i++) ans = (ans + f(i)) % MOD;

    cout << ans << '\n';
  }

  return 0;
}
