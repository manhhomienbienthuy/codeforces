/*!
 * author: manhhomienbienthuy
 * created: 2026-11-22T10:36:01+00:00
 * https://codeforces.com/contest/2289/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    int f = n - k;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    int ans = 0;

    for (int i = 0, j; i < n; i = j) {
      for (j = i + 1; j < n && a[j] == a[i]; j++);

      ans += max(0, j - i - f);
    }

    cout << ans << '\n';
  }

  return 0;
}
