/*!
 * author: manhhomienbienthuy
 * created: 2026-06-28T00:49:31+00:00
 * https://codeforces.com/contest/2240/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i <<= 1) {
      int x = min(k, n / i);
      ans += x;
      n -= x * i;
    }
    cout << ans << "\n";
  }

  return 0;
}
