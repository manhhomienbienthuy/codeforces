/*!
 * author: manhhomienbienthuy
 * created: 2026-10-14T05:04:32+00:00
 * https://codeforces.com/contest/2274/problem/D
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

    int top = 2 * n - 2 * (n % 3 == 0);

    vector<int> ans;

    for (int i = 0; i < 3; i++) {
      for (int j = top; j > 0; j -= 2) ans.push_back(j);
    }

    cout << ans.size() << '\n';

    for (int x : ans) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}
