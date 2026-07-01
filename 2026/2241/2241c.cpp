/*!
 * author: manhhomienbienthuy
 * created: 2026-07-01T01:14:20+00:00
 * https://codeforces.com/contest/2241/problem/C
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
    int d = 1;
    for (int i = 1; i < n; i++) d += s[i] != s[i - 1];
    cout << (d == 2 ? 2 : 1) << '\n';
  }

  return 0;
}
