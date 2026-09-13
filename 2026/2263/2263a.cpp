/*!
 * author: manhhomienbienthuy
 * created: 2026-09-12T15:27:28+00:00
 * https://codeforces.com/contest/2263/problem/A
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

    cout << (s >= (n + 1) / 2 ? "Bessie\n" : "Elsie\n");
  }

  return 0;
}
