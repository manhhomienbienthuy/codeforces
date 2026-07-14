/*!
 * author: manhhomienbienthuy
 * created: 2026-07-13T00:32:45+00:00
 * https://codeforces.com/contest/2246/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

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
    int n;
    cin >> n;

    int minus = 0;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x == -1)
        minus++;
      else
        cnt[x]++;
    }

    int64_t ans = 1;
    int C = 0, prev = -2;
    for (auto& [v, c] : cnt) {
      ans = ans * power(c - 1) % MOD;
      C += v == prev + 1;
      prev = v;
    }

    if (minus) {
      ans = ans * power(minus - 1) % MOD * (1 + C) % MOD;
    }

    cout << ans << '\n';
  }

  return 0;
}
