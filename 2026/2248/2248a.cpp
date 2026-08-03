/*!
 * author: manhhomienbienthuy
 * created: 2026-08-02T03:19:28+00:00
 * https://codeforces.com/contest/2248/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    auto p = s.find('0');
    s.erase(p, 1);

    p = s.find('1');
    s.erase(p, 1);

    cout << s << '\n';
  }

  return 0;
}
