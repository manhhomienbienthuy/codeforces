/*!
 * author: manhhomienbienthuy
 * created: 2026-07-21T00:57:39+00:00
 * https://codeforces.com/gym/704573/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int x = s[0] - '0', y = s[1] - '0', z = s[2] - '0';
  cout << (x + z == y || z == y ? "YES\n" : "NO\n");

  return 0;
}
