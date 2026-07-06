/*!
 * author: manhhomienbienthuy
 * created: 2026-07-06T01:21:57+00:00
 * https://codeforces.com/contest/2205/problem/B
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

    int ans = 1;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        ans *= i;
        while (n % i == 0) n /= i;
      }
    }
    if (n > 1) ans *= n;

    cout << ans << '\n';
  }

  return 0;
}
