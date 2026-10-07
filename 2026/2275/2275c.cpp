/*!
 * author: manhhomienbienthuy
 * created: 2026-10-07T15:09:21+00:00
 * https://codeforces.com/contest/2275/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

const int OFF = 30000;
const int SZ = 60001;

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

    vector<int> v(n - 4), cnt(SZ);

    int64_t ans = 0;

    for (int x = 0; x < n - 4; x++) {
      v[x] = a[x] + a[x + 2] - a[x + 4] + OFF;

      ans += cnt[v[x]] - (x >= 2 && v[x - 2] == v[x]) -
             (x >= 4 && v[x - 4] == v[x]);

      cnt[v[x]]++;
    }

    cout << ans << '\n';
  }

  return 0;
}
