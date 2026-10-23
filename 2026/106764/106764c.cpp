/*!
 * author: manhhomienbienthuy
 * created: 2026-10-21T08:22:06+00:00
 * https://codeforces.com/gym/106764/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

struct state {
  int x, y;
  int pos;
  int dir;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c;
  cin >> r >> c;

  vector<string> grid(r);
  for (string& row : grid) cin >> row;

  vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

  auto check = [&](string& s) -> bool {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (grid[i][j] != s[0]) continue;

        vector visited(r, vector<bool>(c, false));
        stack<state> st;

        st.push({i, j, 0, 0});

        while (!st.empty()) {
          state& cur = st.top();

          if (cur.pos + 1 == (int)s.size()) return true;

          if (cur.dir == 4) {
            visited[cur.x][cur.y] = false;
            st.pop();
            continue;
          }

          visited[cur.x][cur.y] = true;

          int d = cur.dir++, nx = cur.x + dx[d], ny = cur.y + dy[d];

          if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
          if (visited[nx][ny] || grid[nx][ny] != s[cur.pos + 1]) continue;

          st.push({nx, ny, cur.pos + 1, 0});
        }
      }
    }

    return false;
  };

  int q;
  cin >> q;

  while (q--) {
    string s;
    cin >> s;
    cout << (check(s) ? "YES\n" : "NO\n");
  }

  return 0;
}
