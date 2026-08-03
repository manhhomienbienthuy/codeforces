/*!
 * author: manhhomienbienthuy
 * created: 2026-08-03T00:39:56+00:00
 * https://codeforces.com/contest/2248/problem/C
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

    vector<int> a(2 * n);
    for (int& x : a) cin >> x;

    vector<int> pos(n + 1, -1);
    vector<int64_t> dp(2 * n + 1, 0);

    for (int i = 1; i <= 2 * n; i++) {
      dp[i] = dp[i - 1] + 1;

      int p = pos[a[i - 1]];
      if (p != -1) {
        dp[i] = max(dp[i], dp[p - 1] + 1ll * (i - p + 1) * (i - p + 1));
      }

      pos[a[i - 1]] = i;
    }

    cout << dp[2 * n] << '\n';
  }

  return 0;
}
