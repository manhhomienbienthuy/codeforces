/*!
 * author: manhhomienbienthuy
 * created: 2026-06-24T10:09:22+00:00
 * https://codeforces.com/contest/2035/problem/C
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
      cout << n << "\n";
      cout << 2 << " ";
      for (int i = 4; i < n - 1; i++) cout << i << " ";
      cout << 3 << " " << 1 << " " << n - 1 << " " << n << "\n";
    } else {
      int z = n >> 1;
      z |= z >> 1;
      z |= z >> 2;
      z |= z >> 4;
      z |= z >> 8;
      z |= z >> 16;

      cout << (z << 1) + 1 << "\n";

      if (n == 6)
        cout << "4 5 1 2 3 6\n";
      else {
        cout << 2 << " ";
        for (int i = 4; i < z - 1; i++) cout << i << " ";
        for (int i = z + 1; i < n; i++) cout << i << " ";
        cout << 3 << " " << 1 << " " << z - 1 << " " << z << " " << n << "\n";
      }
    };
  }

  return 0;
}
