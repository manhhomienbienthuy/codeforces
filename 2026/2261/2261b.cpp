/*!
 * author: manhhomienbienthuy
 * created: 2026-10-17T14:43:38+00:00
 * https://codeforces.com/contest/2261/problem/B
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

    vector<int> a(n);
    for (int& x : a) cin >> x;

    auto [mn, mx] = ranges::minmax(a);

    int bit_len = bit_width((unsigned)(mn ^ mx));
    int mask = (1 << bit_len) - 1;

    cout << (mx | mask) << '\n';
  }

  return 0;
}
