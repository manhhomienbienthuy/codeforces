/*!
 * author: manhhomienbienthuy
 * created: 2026-06-29T05:06:02+00:00
 * https://codeforces.com/contest/2238/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> f;
    for (int i = 2; i * i <= n; i++) {
      if (n % i) continue;
      int c = 0;
      while (n % i == 0) {
        c++;
        n /= i;
      }
      f.push_back({i, c});
    }
    if (n > 1) f.push_back({n, 1});

    int64_t ans = f.size() - 1;
    for (auto [x, y] : f) ans += y;
    cout << ans << '\n';
  }

  return 0;
}
