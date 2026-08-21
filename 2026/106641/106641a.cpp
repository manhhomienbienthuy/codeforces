/*!
 * author: manhhomienbienthuy
 * created: 2026-08-21T05:30:55+00:00
 * https://codeforces.com/gym/106641/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, a, b;
  cin >> n >> a >> b;
  n--;

  vector<int64_t> ans = {a, b, a ^ b};
  cout << ans[n % 3] << '\n';

  return 0;
}
