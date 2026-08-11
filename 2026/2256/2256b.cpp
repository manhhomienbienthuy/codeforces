/*!
 * author: manhhomienbienthuy
 * created: 2026-08-10T05:55:27+00:00
 * https://codeforces.com/contest/2256/problem/B
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
    string s;

    cin >> n >> s;

    int ans = 1;

    for (int start = 0; start < 2; start++) {
      char cur = '?';
      int choice = 2;

      for (int i = start; i < n; i += 2) {
        if (s[i] == '?' && cur == '?')
          continue;
        else if (cur == '?') {
          choice = 1;
          cur = s[i];
        } else {
          choice = 1;

          if (s[i] == cur) {
            choice = 0;
            break;
          } else {
            cur = cur == '0' ? '1' : '0';
          }
        }
      }

      ans *= choice;

      if (!ans) break;
    }

    cout << ans << '\n';
  }

  return 0;
}
