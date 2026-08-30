/*!
 * author: manhhomienbienthuy
 * created: 2026-08-29T14:34:41+00:00
 * https://codeforces.com/contest/2258/problem/A
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

    cout << __gcd(a[0], a[n - 1]) << '\n';
  }

  return 0;
}
