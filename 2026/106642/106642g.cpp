/*!
 * author: manhhomienbienthuy
 * created: 2026-08-13T02:50:43+00:00
 * https://codeforces.com/gym/106642/problem/G
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  vector<int64_t> a(3), b(3);

  cin >> n;
  for (int64_t& x : a) cin >> x;
  for (int64_t& x : b) cin >> x;

  auto [mn, mx] = ranges::minmax(b);

  int64_t ans = mn + (n - mx);

  set<int64_t> s;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int64_t d = a[i] - b[j];
      if (mx + d > n || mn + d < 1) continue;
      s.insert(d);
    }
  }

  cout << ans - (int64_t)s.size() << '\n';

  return 0;
}
