/*!
 * author: manhhomienbienthuy
 * created: 2026-11-10T04:35:26+00:00
 * https://codeforces.com/gym/106816/problem/5
 */

#include <bits/stdc++.h>
using namespace std;

struct rect {
  int x1, y1, x2, y2, col;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n, vector<int>(m));
  vector<int> cnt(3);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      a[i][j]--;
      cnt[a[i][j]]++;
    }
  }

  vector pref(3, vector<vector<int>>(n + 1, vector<int>(m + 1)));

  for (int c = 0; c < 3; c++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        pref[c][i + 1][j + 1] = pref[c][i][j + 1] + pref[c][i + 1][j] -
                                pref[c][i][j] + (a[i][j] == c);
      }
    }
  }

  auto query = [&](int c, int x1, int y1, int x2, int y2) {
    return pref[c][x2][y2] - pref[c][x1][y2] - pref[c][x2][y1] +
           pref[c][x1][y1];
  };

  const int INF = INT_MAX / 4;
  int ans = INF;

  auto calc = [&](const vector<rect>& rs) {
    int have[3][3] = {};

    for (const rect& r : rs) {
      int h = r.x2 - r.x1;
      int w = r.y2 - r.y1;

      if (h <= 0 || w <= 0) return;
      if (h * w != cnt[r.col]) return;

      for (int c = 0; c < 3; c++) {
        have[c][r.col] += query(c, r.x1, r.y1, r.x2, r.y2);
      }
    }

    int cur = 0;

    for (int x = 0; x < 3; x++) {
      for (int y = x + 1; y < 3; y++) {
        int take = min(have[x][y], have[y][x]);

        have[x][y] -= take;
        have[y][x] -= take;
        cur += take;
      }
    }

    int rem = 0;

    for (int x = 0; x < 3; x++) {
      for (int y = 0; y < 3; y++) {
        if (x != y) rem += have[x][y];
      }
    }

    if (rem % 3 != 0) return;

    cur += 2 * (rem / 3);
    ans = min(ans, cur);
  };

  vector<int> col;

  for (int c = 0; c < 3; c++) {
    if (cnt[c] > 0) col.push_back(c);
  }

  int k = (int)col.size();

  if (k == 1) {
    cout << 0 << '\n';
    return 0;
  }

  sort(col.begin(), col.end());

  do {
    if (k == 2) {
      int c0 = col[0], c1 = col[1];

      if (cnt[c0] % m == 0) {
        int h = cnt[c0] / m;

        if (0 < h && h < n) {
          calc({{0, 0, h, m, c0}, {h, 0, n, m, c1}});
        }
      }

      if (cnt[c0] % n == 0) {
        int w = cnt[c0] / n;

        if (0 < w && w < m) {
          calc({{0, 0, n, w, c0}, {0, w, n, m, c1}});
        }
      }

      continue;
    }

    int c0 = col[0], c1 = col[1], c2 = col[2];

    if (cnt[c0] % m == 0) {
      int h0 = cnt[c0] / m;
      int rh = n - h0;

      if (0 < h0 && 0 < rh) {
        if (cnt[c1] % rh == 0) {
          int w1 = cnt[c1] / rh;

          if (0 < w1 && w1 < m) {
            calc({{0, 0, h0, m, c0}, {h0, 0, n, w1, c1}, {h0, w1, n, m, c2}});
          }
        }

        if (cnt[c1] % m == 0) {
          int h1 = cnt[c1] / m;

          if (0 < h1 && h1 < rh) {
            calc({{0, 0, h0, m, c0},
                  {h0, 0, h0 + h1, m, c1},
                  {h0 + h1, 0, n, m, c2}});
          }
        }
      }
    }

    if (cnt[c0] % m == 0) {
      int h0 = cnt[c0] / m;
      int rh = n - h0;

      if (0 < h0 && 0 < rh) {
        if (cnt[c1] % rh == 0) {
          int w1 = cnt[c1] / rh;

          if (0 < w1 && w1 < m) {
            calc({{rh, 0, n, m, c0}, {0, 0, rh, w1, c1}, {0, w1, rh, m, c2}});
          }
        }

        if (cnt[c1] % m == 0) {
          int h1 = cnt[c1] / m;

          if (0 < h1 && h1 < rh) {
            calc({{rh, 0, n, m, c0}, {0, 0, h1, m, c1}, {h1, 0, rh, m, c2}});
          }
        }
      }
    }

    if (cnt[c0] % n == 0) {
      int w0 = cnt[c0] / n;
      int rw = m - w0;

      if (0 < w0 && 0 < rw) {
        if (cnt[c1] % rw == 0) {
          int h1 = cnt[c1] / rw;

          if (0 < h1 && h1 < n) {
            calc({{0, 0, n, w0, c0}, {0, w0, h1, m, c1}, {h1, w0, n, m, c2}});
          }
        }

        if (cnt[c1] % n == 0) {
          int w1 = cnt[c1] / n;

          if (0 < w1 && w1 < rw) {
            calc({{0, 0, n, w0, c0},
                  {0, w0, n, w0 + w1, c1},
                  {0, w0 + w1, n, m, c2}});
          }
        }
      }
    }

    if (cnt[c0] % n == 0) {
      int w0 = cnt[c0] / n;
      int rw = m - w0;

      if (0 < w0 && 0 < rw) {
        if (cnt[c1] % rw == 0) {
          int h1 = cnt[c1] / rw;

          if (0 < h1 && h1 < n) {
            calc({{0, rw, n, m, c0}, {0, 0, h1, rw, c1}, {h1, 0, n, rw, c2}});
          }
        }

        if (cnt[c1] % n == 0) {
          int w1 = cnt[c1] / n;

          if (0 < w1 && w1 < rw) {
            calc({{0, rw, n, m, c0}, {0, 0, n, w1, c1}, {0, w1, n, rw, c2}});
          }
        }
      }
    }
  } while (next_permutation(col.begin(), col.end()));

  if (ans == INF)
    cout << -1 << '\n';
  else
    cout << ans << '\n';

  return 0;
}
