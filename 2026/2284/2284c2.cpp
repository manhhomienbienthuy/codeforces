/*!
 * author: manhhomienbienthuy
 * created: 2026-11-06T15:08:58+00:00
 * https://codeforces.com/contest/2284/problem/C2
 */

#include <bits/stdc++.h>
using namespace std;

int find_mid(int u, int v) {
  for (int x = u + 1; x < v; x++) {
    if (gcd(u, x) == 1 && gcd(x, v) == 1) return x;
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int a, b;
    cin >> a >> b;

    if (a == b) {
      cout << "0\n";
      continue;
    }

    if (gcd(a, b) == 1) {
      cout << "1\n";
      cout << b - a << '\n';
      continue;
    }

    int c = find_mid(a, b);
    if (c != -1) {
      cout << "2\n";
      cout << c - a << ' ' << b - c << '\n';
      continue;
    }

    int d = find_mid(a + 1, b);
    cout << "3\n";
    cout << 1 << ' ' << d - a - 1 << ' ' << b - d << '\n';
  }

  return 0;
}
