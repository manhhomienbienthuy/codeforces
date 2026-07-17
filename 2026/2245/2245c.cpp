/*!
 * author: manhhomienbienthuy
 * created: 2026-07-17T00:48:36+00:00
 * https://codeforces.com/contest/2245/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    if (k == n) {
      cout << "YES\n";
      for (int i = 1; i < n; i++) cout << i << ' ';
      cout << 0 << '\n';
      continue;
    }

    int x = n ^ k;
    if (x < n) {
      cout << "YES\n";
      for (int i = 1; i < n; i++) {
        if (i != x) cout << i << ' ';
      }
      cout << 0 << ' ' << x << '\n';
      continue;
    }

    int a = x | x >> 1;
    a |= a >> 2;
    a |= a >> 4;
    a |= a >> 8;
    a |= a >> 16;
    a = (a >> 1) + 1;

    if (a >= n) {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";
    int b = x ^ a;
    for (int i = 1; i < n; i++) {
      if (i != a && i != b) cout << i << ' ';
    }
    cout << 0 << ' ' << b << ' ' << a << '\n';
  }

  return 0;
}
