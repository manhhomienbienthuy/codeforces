/*!
 * author: manhhomienbienthuy
 * created: 2026-09-26T11:23:39+00:00
 * https://codeforces.com/contest/2267/problem/D
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

    vector<int> pos(n + 1);

    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      pos[x] = i & 1;
    }

    int p = pos[n];

    vector dp(n + 1, vector(2, vector<bool>(2)));
    dp[n][0][0] = true;

    for (int v = n - 1; v; v--) {
      int b = pos[v] ^ p;

      for (int l = 0; l < 2; l++) {
        for (int r = 0; r < 2; r++) {
          if (!dp[v + 1][l][r]) continue;

          if (b == (1 - l)) dp[v][l ^ 1][r] = true;

          if (b == (1 - r)) dp[v][l][r ^ 1] = true;
        }
      }
    }

    bool ok = false;

    for (int r = 0; r < 2; r++) {
      if (dp[1][1 - p][r]) {
        ok = true;
        break;
      }
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
