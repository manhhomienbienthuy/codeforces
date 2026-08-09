/*!
 * author: manhhomienbienthuy
 * created: 2026-08-09T01:20:57+00:00
 * https://codeforces.com/contest/2252/problem/B
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

    int one = 0, zero = 0;
    char cur = 'a';

    for (char c : s) {
      if (c != cur)
        cur = c;
      else if (cur == '0')
        zero++;
      else
        one++;
    }

    int d = abs(one - zero);

    if (d < 2)
      cout << one + zero << '\n';
    else {
      int z = 0;
      if (one > zero)
        z = (s[0] == '0') + (s[n - 1] == '0');
      else
        z = (s[0] == '1') + (s[n - 1] == '1');

      if (z < d - 1)
        cout << -1 << '\n';
      else
        cout << one + zero + d - 1 << '\n';
    }
  }

  return 0;
}
