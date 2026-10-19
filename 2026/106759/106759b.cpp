/*!
 * author: manhhomienbienthuy
 * created: 2026-10-16T11:58:47+00:00
 * https://codeforces.com/gym/106759/problem/B
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

    sort(a.begin(), a.end());

    int ans = 0;

    for (int i = 0; i < n / 2; i++) {
      ans = max(ans, a[i] + a[n - i - 1]);
    }

    cout << ans << '\n';
  }

  return 0;
}
