/*!
 * author: manhhomienbienthuy
 * created: 2026-09-23T03:48:16+00:00
 * https://codeforces.com/contest/2266/problem/D
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

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] -= i;
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int ans = 0, cur = 1;
    for (int i = 1; i < (int)a.size(); i++) {
      if (a[i] == a[i - 1] + 1)
        cur++;
      else {
        ans = max(ans, cur);
        cur = 1;
      }
    }

    cout << max(ans, cur) << '\n';
  }

  return 0;
}
