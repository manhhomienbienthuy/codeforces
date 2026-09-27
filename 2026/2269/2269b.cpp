/*!
 * author: manhhomienbienthuy
 * created: 2026-09-26T14:55:22+00:00
 * https://codeforces.com/contest/2269/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int calc(int x) {
  int r = 0;

  while (x > 0) {
    int d = x % 10;
    r += d * d;
    x /= 10;
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

    for (int step = 0; step < 1000; step++)
      for (int& x : a) x = calc(x);

    map<int, int> cnt;
    for (int x : a) cnt[x]++;

    int64_t ans = 0;

    for (auto [x, c] : cnt) ans += 1LL * c * (c - 1) / 2;

    cout << ans << '\n';
  }

  return 0;
}
