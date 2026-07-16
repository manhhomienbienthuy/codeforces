/*!
 * author: manhhomienbienthuy
 * created: 2026-07-15T00:34:03+00:00
 * https://codeforces.com/contest/2244/problem/A
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
    int len = 0, cur = 0;
    for (char c : s) {
      if (c == '*') {
        len = max(len, cur);
        cur = 0;
      } else
        cur++;
    }
    len = max(len, cur);

    cout << (len + 1) / 2 << '\n';
  }

  return 0;
}
