/*!
 * author: manhhomienbienthuy
 * created: 2026-10-14T14:53:29+00:00
 * https://codeforces.com/contest/2276/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    int n = (int)s.size();
    bool add = false, sub = false;

    for (int i = 1; i < n - 1; i++) {
      int d = (s[i - 1] != s[i]) + (s[i] != s[i + 1]);

      add = add || (d == 0);
      sub = sub || (d == 2);
    }

    cout << 1 + add + sub << '\n';
  }

  return 0;
}
