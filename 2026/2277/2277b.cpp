/*!
 * author: manhhomienbienthuy
 * created: 2026-10-24T11:17:34+00:00
 * https://codeforces.com/contest/2277/problem/B
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

    int mn = INT_MAX;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      mn = min(mn, x);
    }

    cout << (mn < n ? n : 0) << '\n';
  }

  return 0;
}
