/*!
 * author: manhhomienbienthuy
 * created: 2026-10-14T14:34:44+00:00
 * https://codeforces.com/contest/2276/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int a, b;

    cin >> a >> b;

    cout << (a < b + 1 ? -1 : min(a - b, b)) << '\n';
  }

  return 0;
}
