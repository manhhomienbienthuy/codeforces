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

    int64_t lb = bit_width((uint64_t)(l & -l)) - 1,
            rb = bit_width((uint64_t)((r + 1) & -(r + 1)));

    int64_t s = min(lb, rb);

    int64_t left = l >> s, right = r >> s, sm = left + right;

    s += !(sm & (sm + 1));

    cout << (1LL << s) - 1 << '\n';
  }

  return 0;
}
