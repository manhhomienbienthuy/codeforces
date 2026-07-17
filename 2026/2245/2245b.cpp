/*!
 * author: manhhomienbienthuy
 * created: 2026-07-17T00:41:32+00:00
 * https://codeforces.com/contest/2245/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, c;
    cin >> n >> c;

    int64_t ans = 0;
    int c1 = 0, c2 = 0;
    vector<int> a;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x >= c) {
        ans += x - c;
        c1++;
      } else {
        a.push_back(x);
        c2++;
      }
    }

    c2 = (c2 - c1 + 1) / 2;
    if (c2 > 0) {
      sort(a.begin(), a.end(), greater<>());
      for (int i = 0; i < c2; i++) ans += a[i] - c;
    }

    cout << ans << '\n';
  }

  return 0;
}
