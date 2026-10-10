/*!
 * author: manhhomienbienthuy
 * created: 2026-10-10T00:21:19+00:00
 * https://codeforces.com/gym/106745/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int ask(int m, int r) {
  cout << "? " << m << ' ' << r << '\n';

  int a;
  cin >> a;

  return a;
}

int main() {
  ios::sync_with_stdio(false);
  // cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int ans;

    if (n == 4) {
      ans = ask(2, 1) + ask(3, 1);
    } else {
      int m = (n + 1) >> 1;

      ans = ask(m, m - 1);

      int around = ask(m, 2) - ask(m, 1);

      ans += (ask(m - 1, 1) + ask(m + 1, 1) - around) == 2;

      if (!(n & 1)) {
        int x = ask(m, m - 2) - (m > 3 ? ask(m, m - 3) : 0),
            y = ask(m + 1, m - 1) - ask(m + 1, m - 2), s = ask(n - 1, 1);

        ans += (y - x + s) >> 1;
      }
    }

    cout << "! " << ans << '\n';
  }

  return 0;
}
