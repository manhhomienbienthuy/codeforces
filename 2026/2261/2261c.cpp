/*!
 * author: manhhomienbienthuy
 * created: 2026-10-17T14:59:20+00:00
 * https://codeforces.com/contest/2261/problem/C
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

    int odd = 0, even = 0;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x & 1)
        odd++;
      else
        even++;
    }

    bool ok = (odd == 1 && even == 1) || (odd == 3 && even == 0);

    cout << (ok ? "Larpity\n" : "Moggity\n");
  }

  return 0;
}
