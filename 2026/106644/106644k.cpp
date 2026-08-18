/*!
 * author: manhhomienbienthuy
 * created: 2026-08-14T14:19:47+00:00
 * https://codeforces.com/gym/106644/problem/K
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;

  while (tt--) {
    string s;
    cin >> s;

    int n = (int)s.size();

    vector<int> suf(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] + (s[i] == '7');

    int64_t ans = 0;
    int pref = 0;

    for (int i = 0; i < n; i++) {
      char c = s[i];

      if (c == '7')
        ans += pref;
      else if (c == '6')
        pref++;
      else {
        if (pref <= suf[i])
          ans += pref;
        else
          pref++;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
