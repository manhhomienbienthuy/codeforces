/*!
 * author: manhhomienbienthuy
 * created: 2026-07-29T03:09:54+00:00
 * https://codeforces.com/contest/1993/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    int rem = (n - 1) % k + 1;

    int hi = 0, lo = INT_MAX;
    vector<int> a(n);

    for (int& x : a) {
      cin >> x;
      hi = max(hi, x);
      lo = min(lo, x);
    }

    while (lo <= hi) {
      int mid = (lo + hi) / 2;

      vector<int> dp(n, 0);

      for (int i = 0; i < n; i++) {
        if (i % k >= rem) continue;

        if (i >= k) dp[i] = dp[i - k];

        int cur = i % k ? dp[i - 1] + (a[i] >= mid) : a[i] >= mid;

        dp[i] = max(dp[i], cur);
      }

      if (dp[n - 1] >= rem / 2 + 1)
        lo = mid + 1;
      else
        hi = mid - 1;
    }

    cout << hi << '\n';
  }

  return 0;
}
