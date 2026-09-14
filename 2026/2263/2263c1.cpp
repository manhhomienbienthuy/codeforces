/*!
 * author: manhhomienbienthuy
 * created: 2026-09-12T15:26:36+00:00
 * https://codeforces.com/contest/2263/problem/C1
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

    vector<int> a(n + 1);
    for (int k = 1; k <= n; k++) cin >> a[k];

    vector<int> diff(n + 1);

    for (int k = 1; k <= n; k++) {
      int64_t l = 1ll * a[k] * k;
      int64_t r = 1ll * (a[k] + 1) * k - 1;

      if (l >= n) {
        continue;
      }

      r = min<int64_t>(r, n - 1);

      diff[l]++;
      diff[r + 1]--;
    }

    vector<int> b;
    int cur = 0;

    for (int y = 0; y < n; y++) {
      cur += diff[y];

      if (cur == 0) b.push_back(y);
    }

    cout << b.size() << '\n';

    for (int y : b) cout << y << ' ';
    cout << '\n';
  }

  return 0;
}
