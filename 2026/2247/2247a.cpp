/*!
 * author: manhhomienbienthuy
 * created: 2026-07-20T00:36:47+00:00
 * https://codeforces.com/contest/2247/problem/A
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
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      s += x;
    }

    cout << (s % 4 == 0 ? "YES\n" : "NO\n");
  }

  return 0;
}
