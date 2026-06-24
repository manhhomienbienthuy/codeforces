/*!
 * author: manhhomienbienthuy
 * created: 2026-06-24T00:09:35+00:00
 * https://codeforces.com/contest/2168/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string phase;
  cin >> phase;

  if (phase == "first") {
    int t;
    cin >> t;
    while (t--) {
      int x;
      cin >> x;
      x--;
      vector<bool> used(20, false);
      int d = 0, cnt = 0;
      for (int i = 0; i < 15; i++) {
        int a = (x >> i) & 1;
        if (a > 0) {
          used[i] = true;
          d ^= (i + 1);
          cnt++;
        }
      }
      int c = 1;
      for (int i = 15; i < 19; i++) {
        if ((d >> (i - 15)) & 1) {
          used[i] = true;
          c ^= 1;
          cnt++;
        }
      }
      used[19] = c;
      cnt += used[19];
      cout << cnt << "\n";
      for (int i = 0; i < 20; i++)
        if (used[i]) cout << i + 1 << " ";
      cout << "\n";
    }

  } else {
    int t;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      vector<int> s(n);
      int ans = 0, rev_c = 0, rev_d = 0, calc_c = 1, calc_d = 0;
      for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        if (x == 19)
          rev_c = 1;
        else if (x < 15) {
          ans |= 1 << x;
          calc_d ^= (x + 1);
        } else {
          calc_c ^= 1;
          rev_d |= 1 << (x - 15);
        }
      }
      if (calc_c == rev_c && calc_d != rev_d) {
        ans ^= 1 << ((rev_d ^ calc_d) - 1);
      }
      cout << ans + 1 << "\n";
    }
  }

  return 0;
}
