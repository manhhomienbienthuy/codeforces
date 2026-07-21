/*!
 * author: manhhomienbienthuy
 * created: 2026-07-21T01:15:00+00:00
 * https://codeforces.com/gym/704573/problem/C1
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);

  int64_t s = 0;
  for (auto& x : a) {
    cin >> x;
    s += x;
  }

  int64_t l = 1, r = s / k;
  while (l <= r) {
    int64_t m = (l + r) / 2;
    s = 0;
    for (int x : a) s += x / m;
    if (s >= k)
      l = m + 1;
    else
      r = m - 1;
  }

  cout << r << '\n';
  return 0;
}
