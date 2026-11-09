/*!
 * author: manhhomienbienthuy
 * created: 2026-11-09T02:31:17+00:00
 * https://codeforces.com/gym/106812/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int64_t pw(int64_t a, int64_t p, int64_t m) {
  int64_t r = 1;

  for (a %= m; p > 0; p >>= 1, a = a * a % m) {
    if (p & 1) r = r * a % m;
  }

  return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, r;
  cin >> n >> m >> r;

  vector<int64_t> a(n);
  int64_t s = 0;

  for (int i = 0; i < n; i++) {
    a[i] = pw(i + 1, i + 1, m);
    s = (s + a[i]) % m;
  }

  for (int i = 0; i < n; i++) {
    if ((s - a[i] + m) % m == r) {
      cout << i + 1 << '\n';
      return 0;
    }
  }

  cout << 0 << '\n';
  return 0;
}
