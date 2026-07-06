/*!
 * author: manhhomienbienthuy
 * created: 2026-07-03T09:06:04+00:00
 * https://codeforces.com/contest/2215/problem/E
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
    string s;
    cin >> n >> s;

    vector<vector<int>> dp1(n + 1, vector<int>(n + 1, INT_MIN));
    vector<vector<int>> dp2(n + 1, vector<int>(n + 1, INT_MIN));
    dp1[0][0] = 0;

    for (char c : s) {
      for (int e = 0; e <= n; e++) {
        fill(dp2[e].begin(), dp2[e].end(), INT_MIN);
      }

      vector<int> opts;
      if (c == 'T') {
        opts.push_back(-1);
      } else if (c == 'F') {
        opts.push_back(+1);
      } else {
        opts.push_back(-1);
        opts.push_back(+1);
      }

      for (int e = 0; e <= n; e++) {
        for (int k = 0; k <= n; k++) {
          int curW = dp1[e][k];
          if (curW == INT_MIN) continue;

          for (int w : opts) {
            int ne = max(0, e + w);
            int nk = max(k, ne);
            dp2[ne][nk] = max(dp2[ne][nk], curW + w);
          }
        }
      }

      dp1.swap(dp2);
    }

    int best = INT_MIN;

    for (int e = 0; e <= n; e++) {
      for (int k = 0; k <= n; k++) {
        if (dp1[e][k] == INT_MIN) continue;
        best = max(best, dp1[e][k] - 2 * k);
      }
    }

    cout << (n + best) / 2 << '\n';
  }

  return 0;
}
