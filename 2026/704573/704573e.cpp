/*!
 * author: manhhomienbienthuy
 * created: 2026-07-21T03:25:39+00:00
 * https://codeforces.com/gym/704573/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int64_t sad(int64_t m) { return m * (m + 1) * (m + 2) / 6; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int64_t> c(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  if (n == 1) {
    cout << c[1] << '\n';
    return 0;
  }

  vector<int64_t> dp(n + 1, LLONG_MAX);
  dp[n] = c[n];

  for (int i = n - 1; i > 1; i--) {
    int64_t best = LLONG_MAX;

    for (int j = i + k; j <= n; j++) {
      if (dp[j] == LLONG_MAX) continue;
      best = min(best, dp[j] + sad(j - i - 1));
    }

    if (best != LLONG_MAX) {
      dp[i] = c[i] + best;
    }
  }

  int64_t best = LLONG_MAX;
  for (int j = 2; j <= n; j++) {
    if (dp[j] == LLONG_MAX) continue;
    best = min(best, dp[j] + sad(j - 1 - 1));
  }

  cout << c[1] + best << '\n';
  return 0;
}
