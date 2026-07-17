/*!
 * author: manhhomienbienthuy
 * created: 2026-07-17T00:38:33+00:00
 * https://codeforces.com/contest/2245/problem/A
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

    if (n < 2 * k) {
      cout << -1 << '\n';
      continue;
    }

    int ans = 0;
    for (int i = 0; i < k; i++) {
      ans += s[i] == 'L';
      ans += s[n - i - 1] == 'R';
    }

    cout << ans << '\n';
  }

  return 0;
}
