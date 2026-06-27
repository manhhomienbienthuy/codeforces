/*!
 * author: manhhomienbienthuy
 * created: 2026-06-27T09:35:08+00:00
 * https://codeforces.com/contest/2148/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m, p = 0, s = 0;
    cin >> n >> m;
    while (n--) {
      int a, b;
      cin >> a >> b;
      int d = a - p;
      m -= s ^ b ^ (d & 1);
      s = b;
      p = a;
    }
    cout << m << "\n";
  }

  return 0;
}
