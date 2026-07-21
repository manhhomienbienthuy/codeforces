/*!
 * author: manhhomienbienthuy
 * created: 2026-07-21T01:00:21+00:00
 * https://codeforces.com/gym/704573/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());

  int prev = -1;
  int64_t ans = 0;
  for (int x : a) {
    ans += max(0, prev + 1 - x);
    prev = max(prev + 1, x);
  }

  cout << ans << '\n';
  return 0;
}
