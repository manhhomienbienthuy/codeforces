/*!
 * author: manhhomienbienthuy
 * created: 2026-08-10T06:23:55+00:00
 * https://codeforces.com/contest/2256/problem/C
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
    string s;

    cin >> n >> k >> s;
    n <<= 1;

    int red = 0, blue = 0;

    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        bool next_ok = (s[(i + 1) % n] == '0'), is_red = !(i & 1);

        if (next_ok ^ is_red) {
          blue++;
        } else {
          red++;
        }
      }
    }

    cout << red << ' ' << blue << '\n';
  }

  return 0;
}
