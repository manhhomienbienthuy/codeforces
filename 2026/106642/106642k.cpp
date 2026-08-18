/*!
 * author: manhhomienbienthuy
 * created: 2026-08-13T09:16:25+00:00
 * https://codeforces.com/gym/106642/problem/K
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;

  while (tt--) {
    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    vector<int> r(n, 0), c(m, 0);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == '1') {
          r[i]++;
          c[j]++;
        }
      }
    }

    int64_t base = 0;
    vector<int64_t> row_gain(n, 0), col_gain(m, 0);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == '1') {
          base += int64_t(r[i] - 1) * (c[j] - 1);

          row_gain[i] += c[j] - 1;
          col_gain[j] += r[i] - 1;
        }
      }
    }

    int64_t mx = -1, cnt = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == '0') {
          int64_t cur = base + row_gain[i] + col_gain[j] + 1LL * r[i] * c[j];

          if (cur > mx) {
            mx = cur;
            cnt = 1;
          } else if (cur == mx) {
            cnt++;
          }
        }
      }
    }

    cout << mx << ' ' << cnt << '\n';
  }

  return 0;
}
