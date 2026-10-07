/*!
 * author: manhhomienbienthuy
 * created: 2026-10-07T06:55:45+00:00
 * https://codeforces.com/gym/106744/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;

  cin >> n >> k;

  int64_t m;
  for (m = n - 1; m > 0; m--) {
    int64_t s = (m + n - 1) * (n - m) / 2;
    if (s > k) break;
  }

  m++;

  vector<int64_t> a(n);

  for (int64_t i = 0; i < m; i++) a[i] = n - m + 1 + i;
  for (int64_t i = n - 1; i >= m; i--) a[i] = n - i;

  k -= (m + n - 1) * (n - m) / 2;
  rotate(a.begin(), a.begin() + 1, a.begin() + k + 1);

  for (auto x : a) cout << x << ' ';
  cout << '\n';

  return 0;
}
