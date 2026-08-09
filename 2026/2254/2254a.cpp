/*!
 * author: manhhomienbienthuy
 * created: 2026-08-07T12:11:16+00:00
 * https://codeforces.com/contest/2254/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    vector<int> a(3);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    cout << min(a[1] - a[0], a[2] - a[1]) << '\n';
  }

  return 0;
}
