/*!
 * author: manhhomienbienthuy
 * created: 2026-08-29T15:40:04+00:00
 * https://codeforces.com/contest/2258/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int ask(int u, int v, int d) {
  cout << "? " << u << ' ' << v << ' ' << d << endl;

  int res;
  cin >> res;

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int u = 1;
    int d = 0;

    for (int x = 2; x <= n; x++) {
      if (!ask(1, x, d + 1)) continue;

      u = x;
      d++;

      while (d < n - 1 && ask(1, u, d + 1)) d++;
    }

    int v = 1;

    for (int x = 2; x <= n; x++) {
      if (x == u) continue;

      if (!ask(u, x, d + 1)) continue;

      v = x;
      d++;

      while (d < n - 1 && ask(u, v, d + 1)) d++;
    }

    cout << "! " << u << ' ' << v << ' ' << d << endl;
  }

  return 0;
}
