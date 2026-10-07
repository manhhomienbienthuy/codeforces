/*!
 * author: manhhomienbienthuy
 * created: 2026-10-07T06:23:11+00:00
 * https://codeforces.com/gym/106744/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int socks = 0, s_white = 0, s_yellow = 0, s_red = 0, s_green = 0, s_dark = 0,
      t_white = 0, t_yellow = 0, t_red = 0, t_green = 0, t_dark = 0,
      j_white = 0, j_yellow = 0, j_red = 0, j_green = 0, j_dark = 0;

  while (n--) {
    string c, t;
    cin >> c >> t;

    if (t == "Socks")
      socks = 1;
    else if (t == "T-shirt") {
      if (c == "White")
        t_white = 1;
      else if (c == "Yellow")
        t_yellow = 1;
      else if (c == "Red")
        t_red = 1;
      else if (c == "Green")
        t_green = 1;
      else
        t_dark = 1;
    } else if (t == "Hoodie") {
      if (c == "White")
        s_white++;
      else if (c == "Yellow")
        s_yellow++;
      else if (c == "Red")
        s_red++;
      else if (c == "Green")
        s_green++;
      else
        s_dark++;
    } else {
      if (c == "White")
        j_white++;
      else if (c == "Yellow")
        j_yellow++;
      else if (c == "Red")
        j_red++;
      else if (c == "Green")
        j_green++;
      else
        j_dark++;
    }
  }

  int ans = socks + t_white + t_yellow + t_red + t_green + t_dark +
            (s_white + j_white + 1) / 2 + (s_yellow + j_yellow + 1) / 2 +
            (s_red + j_red + 1) / 2 + (s_green + j_green + 1) / 2 +
            (s_dark + j_dark + 1) / 2;

  cout << ans << '\n';

  return 0;
}
