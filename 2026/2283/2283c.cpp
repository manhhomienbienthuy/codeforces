/*!
 * author: manhhomienbienthuy
 * created: 2026-11-04T14:58:44+00:00
 * https://codeforces.com/contest/2283/problem/C
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

    int ans = 0;
    if (n % 4 == 0)
      ans = n;
    else if (n % 4 == 1)
      ans = 1;
    else if (n % 4 == 2)
      ans = n + 1;

    vector<bool> d(n);

    for (int i = n; i >= 1; i--) {
      if ((ans ^ i ^ (i << 1)) > ans) {
        d[i - 1] = true;
        ans ^= i ^ (i << 1);
      }
    }

    for (int x : d) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}
