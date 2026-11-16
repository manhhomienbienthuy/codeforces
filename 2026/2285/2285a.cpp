/*!
 * author: manhhomienbienthuy
 * created: 2026-11-15T14:38:05+00:00
 * https://codeforces.com/contest/2285/problem/A
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

    if (n < 4) {
      cout << -1 << '\n';
    } else {
      vector<int> ans(n);
      iota(ans.begin(), ans.end(), 1);
      swap(ans[0], ans[3]);

      for (auto x : ans) cout << x << ' ';
      cout << '\n';
    }
  }

  return 0;
}
