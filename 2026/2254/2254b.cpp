/*!
 * author: manhhomienbienthuy
 * created: 2026-08-07T12:15:11+00:00
 * https://codeforces.com/contest/2254/problem/B
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

    string ans = string(1, s[0]);
    char cur = s[0];
    bool done = false, alone = false;

    for (int i = 1; i < n - 1; i++) {
      if (s[i] != cur) {
        alone = alone || (s[i] != s[i + 1]);

        if (!done && s[i + 1] == cur)
          done = true;
        else {
          ans += s[i];
          cur = s[i];
        }
      }
    }

    if (s[n - 1] != cur) ans += s[n - 1];

    cout << ans.size() - (!done && alone) << '\n';
  }

  return 0;
}
