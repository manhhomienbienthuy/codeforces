/*!
 * author: manhhomienbienthuy
 * created: 2026-09-26T07:29:43+00:00
 * https://codeforces.com/contest/2267/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, x;
    cin >> n >> x;

    vector<int> divs;

    for (int p = 2; p * p <= x; p++) {
      if (x % p) continue;

      divs.push_back(p);
      while (x % p == 0) x /= p;
    }

    if (x > 1) divs.push_back(x);

    int m = (int)divs.size();
    vector<int64_t> calc(m + 1);

    for (int i = 0; i < n; i++) {
      int y;
      cin >> y;

      for (int j = 0; j < m; j++) {
        if (y % divs[j] == 0) calc[j] += y;
      }
    }

    cout << ranges::max(calc) << '\n';
  }

  return 0;
}
