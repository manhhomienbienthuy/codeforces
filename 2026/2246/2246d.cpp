/*!
 * author: manhhomienbienthuy
 * created: 2026-07-13T05:58:19+00:00
 * https://codeforces.com/contest/2246/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int calc(int x) {
  int res = 0;
  while (x) {
    res += 1 + (x & 1);
    x >>= 1;
  }

  return res - 1;
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
    for (auto& x : a) cin >> x;

    int64_t ans = LLONG_MAX;
    for (int k = 0; k < 18; k++) {
      int64_t cur = k;
      int m = 1 << k;

      for (int x : a) {
        int r = x % m;
        int add = (m - r) % m;
        int y = (x + add) >> k;
        int step = add + calc(y);
        if (y > 1) {
          for (int i = 1; i <= 32; i++)
            step = min(step, add + i * m + calc(y + i));
        }
        cur += step;
      }

      ans = min(ans, cur);
    }

    cout << ans << '\n';
  }

  return 0;
}
