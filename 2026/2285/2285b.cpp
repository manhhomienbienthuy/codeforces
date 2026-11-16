/*!
 * author: manhhomienbienthuy
 * created: 2026-11-15T14:39:56+00:00
 * https://codeforces.com/contest/2285/problem/B
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
    string s;
    cin >> n >> k >> s;

    int one = 0;
    for (char c : s) one += (c == '1');
    int zero = n - one;

    int64_t mx = min(n, max(one, zero) + k);

    int64_t ans = 1;
    ans += mx * (mx + 1) / 2;
    ans += (n - mx) * (n - mx + 1) / 2;
    cout << ans << '\n';
  }

  return 0;
}
