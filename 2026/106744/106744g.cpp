/*!
 * author: manhhomienbienthuy
 * created: 2026-10-07T01:28:47+00:00
 * https://codeforces.com/gym/106744/problem/G
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;

  cin >> n >> k;

  int64_t s = k * (k + 1) / 2;

  int64_t q = n / s, r = n % s;

  vector<int64_t> ans(k, q);

  for (int64_t i = k; r > 0 && i > 0; i--) {
    if (r >= i) {
      ans[i - 1]++;
      r -= i;
    }
  }

  for (auto x : ans) cout << x << ' ';
  cout << '\n';

  return 0;
}
