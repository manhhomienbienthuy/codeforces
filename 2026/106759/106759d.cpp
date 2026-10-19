/*!
 * author: manhhomienbienthuy
 * created: 2026-10-19T00:32:51+00:00
 * https://codeforces.com/gym/106759/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k, p;
    cin >> n >> k >> p;

    vector<pair<int, int>> ops(k);
    for (auto& [l, r] : ops) cin >> l >> r;

    int s = 1;

    for (int i = k - 1; i >= 0; i--) {
      auto [l, r] = ops[i];

      if (p >= l && p <= r) {
        p = l + r - p;
        s = -s;
      }
    }

    cout << p * s << '\n';
  }

  return 0;
}
