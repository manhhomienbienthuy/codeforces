/*!
 * author: manhhomienbienthuy
 * created: 2026-07-27T03:33:26+00:00
 * https://codeforces.com/contest/2250/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<vector<int>> pos(n + 1);

    for (int i = 1; i <= n - 1; i++) {
      int x;
      cin >> x;
      if (1 <= x && x <= n) pos[x].push_back(i);
    }

    vector<int> cnt(n + 1, 0), l(n + 1, -1), r(n + 1, -1);

    int cur_cnt = 0, mn = n, mx = -1;
    bool ok = true;

    for (int x = n - 1; x; x--) {
      for (int p : pos[x]) {
        cur_cnt++;
        mn = min(mn, p);
        mx = max(mx, p);
      }

      cnt[x] = cur_cnt;

      if (cur_cnt == 0) {
        l[x] = r[x] = -1;
        continue;
      }

      if (mx - mn + 1 != cur_cnt) ok = false;

      l[x] = mn;
      r[x] = mx + 1;
    }

    if (!ok || cnt[n - 1] == 0) {
      cout << 0 << '\n';
      continue;
    }

    int64_t ans = 2;

    for (int x = n - 2; x; x--) {
      if (cnt[x] == 0) {
        ok = false;
        break;
      }

      if (l[x] == l[x + 1] && r[x] == r[x + 1]) {
        int len = r[x] - l[x] + 1;
        int free = len - (n - x);

        if (free <= 0) {
          ok = false;
          break;
        }

        ans = ans * free % MOD;
      } else if (l[x] != l[x + 1] && r[x] != r[x + 1]) {
        ok = false;
        break;
      }
    }

    cout << (ok ? ans : 0) << '\n';
  }

  return 0;
}
