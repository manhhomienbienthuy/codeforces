/*!
 * author: manhhomienbienthuy
 * created: 2026-06-28T05:27:32+00:00
 * https://codeforces.com/contest/2240/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int64_t power(int64_t p) {
  if (p < 30) return (1 << p) % MOD;
  int64_t r = power(p / 2);
  return (r * r * (1 << (p & 1))) % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    int64_t f = 1ll * n * m - 1ll * (n - r + 1) * (m - c + 1);
    cout << power(f) << "\n";
  }

  return 0;
}
