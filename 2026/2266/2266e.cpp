/*!
 * author: manhhomienbienthuy
 * created: 2026-09-23T03:52:56+00:00
 * https://codeforces.com/contest/2266/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> divs(MAX);

  for (int p = 2; p < MAX; p++) {
    if (!divs[p].empty()) continue;

    for (int x = p; x < MAX; x += p) {
      divs[x].push_back(p);
    }
  }

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int64_t> dp(n + 1);

    for (int x = k + 1; x <= n; x++) {
      dp[x] = LLONG_MAX;

      for (int p : divs[x]) {
        dp[x] = min(dp[x], 1 + dp[x / p] * p);
      }
    }

    int64_t ans = 0;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ans += dp[x];
    }

    cout << ans << '\n';
  }

  return 0;
}
