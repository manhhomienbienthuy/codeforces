/*!
 * author: manhhomienbienthuy
 * created: 2026-08-07T12:33:10+00:00
 * https://codeforces.com/contest/2254/problem/C1
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
    string a, b;
    cin >> n >> a >> b;

    int odd = 0, even = 0;
    for (int i = 0; i < n; i += 2) {
      if (a[i] == '1' && b[i] == '0')
        even++;
      else if (a[i] == '0' && b[i] == '1')
        even--;
    }

    for (int i = 1; i < n; i += 2) {
      if (a[i] == '1' && b[i] == '0')
        odd++;
      else if (a[i] == '0' && b[i] == '1')
        odd--;
    }

    cout << (!odd && !even ? "YES\n" : "NO\n");
  }

  return 0;
}
