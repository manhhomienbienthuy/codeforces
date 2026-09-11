/*!
 * author: manhhomienbienthuy
 * created: 2026-09-09T14:28:45+00:00
 * https://codeforces.com/contest/2260/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

bool check(const string& s, int n, int mx) {
  int lim = 2 * mx;

  bool ans = false;

  vector dp(n + 1, vector<bool>(2 * lim + 1));

  dp[0][lim] = true;

  for (int i = 1; i <= n; i++) {
    char ch = s[i - 1];

    for (int p = -lim; p <= lim; p++) {
      if (!dp[i - 1][p + lim]) continue;

      int l = max(-lim, p - mx);
      int r = min(lim, p + mx);

      for (int q = l; q <= r; q++) {
        if (q == p) continue;

        bool ok = (ch == '+' && q > 0) || (ch == '-' && q < 0) ||
                  (ch == '0' && q == 0);

        if (ok) {
          dp[i][q + lim] = true;
          if (i == n) ans = true;
        }
      }
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;

    cin >> n >> s;

    int ans = -1;

    for (int c = 1; c <= 3; c++) {
      if (check(s, n, c)) {
        ans = c;
        break;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
