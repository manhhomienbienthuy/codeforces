/*!
 * author: manhhomienbienthuy
 * created: 2026-09-23T03:46:24+00:00
 * https://codeforces.com/contest/2266/problem/C
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
    string s;

    cin >> n >> s;

    int x = 0, y = 0;

    for (char c : s) {
      if (c == s[0])
        x++;
      else if (c > s[0])
        y = max(x + 1, y + 1);
    }

    cout << n - max(x, y) << '\n';
  }

  return 0;
}
