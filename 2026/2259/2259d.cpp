/*!
 * author: manhhomienbienthuy
 * created: 2026-09-05T16:44:57+00:00
 * https://codeforces.com/contest/2259/problem/D
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
    cin >> n;

    vector<int> a(n);
    int cnt = 0;

    for (int& x : a) {
      cin >> x;
      cnt += !x;
    }

    if (!cnt) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) cout << char('A' + (i % 3));
      cout << '\n';
    } else if (cnt == 1)
      cout << "NO\n";
    else {
      cout << "YES\n";
      cnt = 0;
      for (int i = 0; i < n; i++) {
        if (a[i])
          cout << 'C';
        else
          cout << char('A' + (cnt++ % 2));
      }
      cout << '\n';
    }
  }

  return 0;
}
