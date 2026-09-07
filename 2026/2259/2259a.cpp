/*!
 * author: manhhomienbienthuy
 * created: 2026-09-05T16:49:16+00:00
 * https://codeforces.com/contest/2259/problem/A
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

    int ans = 0;

    for (int i = 0; i < n; i += k) {
      bool ok = true;
      for (int j = i; j < i + k; j++) ok = ok && s[j] == '1';
      ans += ok;
    }

    cout << ans << '\n';
  }

  return 0;
}
