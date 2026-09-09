/*!
 * author: manhhomienbienthuy
 * created: 2026-09-09T00:11:21+00:00
 * https://codeforces.com/contest/2260/problem/A
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
    int s = 0;

    for (int& x : a) {
      cin >> x;
      s += x;
    }

    if (s > n - 2) {
      cout << -1 << '\n';
    } else {
      cout << 2 - (a[0] == 0) - (a[n - 1] == 0) << '\n';
    }
  }

  return 0;
}
