/*!
 * author: manhhomienbienthuy
 * created: 2026-10-17T14:35:08+00:00
 * https://codeforces.com/contest/2261/problem/A
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

    int cnt = 0, l = -1, r = -1;

    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        cnt++;
        if (l == -1) l = i;
        r = i;
      }
    }

    if (cnt == 1)
      cout << 0 << '\n';
    else if (cnt == 2)
      cout << 1 << '\n';
    else
      cout << r - l << '\n';
  }

  return 0;
}
