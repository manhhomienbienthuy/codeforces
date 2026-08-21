/*!
 * author: manhhomienbienthuy
 * created: 2026-08-21T07:17:08+00:00
 * https://codeforces.com/gym/106641/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> pw[11];

  for (int x = 2; x <= 10; x++) {
    for (int b = 1;; b++) {
      int64_t v = 1;

      for (int i = 0; i < x; i++) {
        v *= b;
        if (v > MAXN) break;
      }

      if (v > MAXN) break;

      pw[x].push_back((int)v);
    }
  }

  vector dp(11, vector<int>(MAXN + 1, INF)), pre(11, vector<int>(MAXN + 1, -1));

  for (int x = 2; x <= 10; x++) {
    // pre-calc dp[x]
    dp[x][0] = 0;

    for (int j = 0; j < (int)pw[x].size(); j++) {
      int coin = pw[x][j];

      for (int s = coin; s <= MAXN; s++) {
        if (dp[x][s - coin] + 1 < dp[x][s]) {
          dp[x][s] = dp[x][s - coin] + 1;
          pre[x][s] = j;
        }
      }
    }
  }

  int t;
  cin >> t;

  while (t--) {
    int n, x;
    cin >> n >> x;

    if (x == 1) {
      cout << 1 << '\n';
      cout << n << '\n';
      continue;
    }

    cout << dp[x][n] << '\n';

    vector<int> ans;

    while (n) {
      ans.push_back(pre[x][n] + 1);
      n -= pw[x][pre[x][n]];
    }

    for (int i = (int)ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
    cout << '\n';
  }

  return 0;
}
