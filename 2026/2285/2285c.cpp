/*!
 * author: manhhomienbienthuy
 * created: 2026-11-15T14:50:43+00:00
 * https://codeforces.com/contest/2285/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int64_t pw(int64_t a, int64_t p, int64_t m = MOD) {
  int64_t r = 1;

  for (a %= m; p > 0; p >>= 1, a = a * a % m) {
    if (p & 1) r = r * a % m;
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

    vector<int> a(n);
    for (int& x : a) cin >> x;

    sort(a.begin(), a.end(), greater<>());

    int64_t ans = 1;

    for (int i = 0; i < n; i++) {
      if (i < n - 1 && a[i] == a[i + 1]) break;

      ans = (ans + pw(a[i] - 1, i + 1, MOD)) % MOD;
    }

    cout << ans << '\n';
  }

  return 0;
}
