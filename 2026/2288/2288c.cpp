/*!
 * author: manhhomienbienthuy
 * created: 2026-11-24T01:11:04+00:00
 * https://codeforces.com/contest/2288/problem/C
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

    vector<int> a(n);
    for (int& y : a) {
      cin >> y;
      y = (y - 1) / x;
    }

    sort(a.begin(), a.end());

    int ans = 0;

    for (int i = 0; i < n - 1; i++) ans = max(ans, a[i] - i);

    cout << ans << '\n';
  }

  return 0;
}
