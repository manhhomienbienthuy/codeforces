/*!
 * author: manhhomienbienthuy
 * created: 2026-09-26T04:59:43+00:00
 * https://codeforces.com/contest/2267/problem/A
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
    char c;
    string s;

    cin >> n >> c >> s;

    int ans = 0;

    for (int i = 0; i < n / 2; i++) {
      if (s[i] == s[n - i - 1]) continue;

      ans += (s[i] != c) + (s[n - i - 1] != c);
    }

    cout << ans << '\n';
  }

  return 0;
}
