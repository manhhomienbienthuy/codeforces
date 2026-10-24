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

    vector<int> a(n);
    for (int& x : a) cin >> x;

    int mn = ranges::min(a);
    if (mn <= n - 1)
      cout << n << '\n';
    else
      cout << 0 << '\n';
  }

  return 0;
}
