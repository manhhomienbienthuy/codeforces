/*!
 * author: manhhomienbienthuy
 * created: 2026-07-08T08:14:36+00:00
 * https://codeforces.com/contest/2242/problem/F
 */

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (auto& x : a) cin >> x;

  vector<int> ans(n, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (ans[j] >= a[i])
        ans[j] -= a[i];
      else
        ans[j] += a[i];
    }
  }

  for (int i = n - 1; i >= 0; i--) cout << ans[i] << ' ';
  cout << '\n';

  return 0;
}
