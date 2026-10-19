/*!
 * author: manhhomienbienthuy
 * created: 2026-10-14T15:26:51+00:00
 * https://codeforces.com/contest/2276/problem/E
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

    vector next_pos(n + 2, vector<int>(10, n));

    for (int i = n - 1; i >= 0; i--) {
      next_pos[i] = next_pos[i + 1];
      next_pos[i][s[i] - '0'] = i;
    }

    vector<int64_t> ds(n + 2), dc(n + 2);

    for (int l = 0; l < n; l++) {
      int p202 = next_pos[l][2];
      p202 = next_pos[p202 + 1][0];
      p202 = next_pos[p202 + 1][2];

      int p2025 = next_pos[p202 + 1][5], p2026 = next_pos[p202 + 1][6];

      if (p2025 == n || p2026 < p2025) continue;

      int64_t ways = p2026 - p2025;

      dc[l] += ways;
      dc[p2025 + 1] -= ways;

      ds[p2025 + 1] -= 1;
      ds[p2026] += 1;

      dc[p2025 + 1] += p2026;
      dc[p2026] -= p2026;
    }

    int64_t sl = 0, cn = 0;

    for (int i = 0; i < n; i++) {
      sl += ds[i];
      cn += dc[i];

      int64_t all = 1LL * (i + 1) * (n - i), bad = sl * i + cn;

      cout << all - bad << ' ';
    }

    cout << '\n';
  }

  return 0;
}
