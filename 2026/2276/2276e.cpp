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

    vector next_pos(n + 1, vector<int>(10, n));

    for (int i = n - 1; i >= 0; i--) {
      next_pos[i] = next_pos[i + 1];
      next_pos[i][s[i] - '0'] = i;
    }

    vector<int64_t> ds(n + 2), dc(n + 2);

    auto add = [&](int l, int r, int64_t sl, int64_t cn) {
      if (l > r) return;

      ds[l] += sl;
      ds[r + 1] -= sl;

      dc[l] += cn;
      dc[r + 1] -= cn;
    };

    for (int l = 0; l < n; l++) {
      int p1 = next_pos[l][2];

      if (p1 == n) continue;

      int p2 = next_pos[p1 + 1][0];

      if (p2 == n) continue;

      int p3 = next_pos[p2 + 1][2];

      if (p3 == n) continue;

      int p5 = next_pos[p3 + 1][5];

      if (p5 == n) continue;

      int p6 = next_pos[p3 + 1][6];

      if (p6 != n && p6 < p5) continue;

      int r = p6 - 1;

      int64_t ways = r - p5 + 1;

      add(l, p5, 0, ways);
      add(p5 + 1, r, -1, r + 1);
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
