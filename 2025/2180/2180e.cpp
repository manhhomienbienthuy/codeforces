/*!
 * author: manhhomienbienthuy
 * created: 2026-11-27T00:54:13+00:00
 * https://codeforces.com/contest/2180/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int64_t l, r;
    cin >> l >> r;

    int64_t x = l ^ r;

    if (!x) {
      cout << 0 << '\n';
      continue;
    }

    int64_t q = 1LL << (bit_width((uint64_t)x) - 1);

    int64_t lo = l & (q - 1), hi = r & (q - 1), left = q - lo, right = hi + 1;

    int64_t base = min(left & -left, right & -right);

    if (left == right) base <<= 1;

    cout << base - 1 << '\n';
  }

  return 0;
}
