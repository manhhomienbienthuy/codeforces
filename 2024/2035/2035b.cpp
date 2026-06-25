/*!
 * author: manhhomienbienthuy
 * created: 2026-06-24T09:43:28+00:00
 * https://codeforces.com/contest/2035/problem/B
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
    if (n & 1) {
      if (n < 5)
        cout << -1 << "\n";
      else {
        for (int i = 0; i < n - 5; i++) {
          cout << 3;
        }
        cout << 36366 << "\n";
      }
    } else {
      for (int i = 0; i < n - 2; i++) {
        cout << 3;
      }
      cout << 66 << "\n";
    }
  }

  return 0;
}
