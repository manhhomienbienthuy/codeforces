/*!
 * author: manhhomienbienthuy
 * created: 2026-11-15T15:37:10+00:00
 * https://codeforces.com/contest/2285/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

struct state {
  deque<int> pos;
  int last = -1;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    int ans = min(n, k + 1);

    if (ans == n) {
      cout << n << '\n';
      continue;
    }

    unordered_map<uint64_t, state> pos;

    for (int r = 0; r < n; r++) {
      unordered_map<uint64_t, vector<int>> cur;

      for (int l = max(0, r - k - 1); l < r; l++) {
        int d = a[r] - a[l];

        if (d % (l - r) != 0) continue;

        d /= (r - l);
        int c = a[r] - d * r;

        uint64_t key = (uint64_t)(uint32_t)d << 32 | (uint32_t)c;

        cur[key].push_back(l);
      }

      for (auto& [key, add] : cur) {
        state& st = pos[key];

        for (int x : add) {
          if (x > st.last) {
            st.pos.push_back(x);
            st.last = x;
          }
        }

        if (r > st.last) {
          st.pos.push_back(r);
          st.last = r;
        }

        while (!st.pos.empty()) {
          int need = st.pos.back() - st.pos.front() + 1 - (int)st.pos.size();

          if (need <= k) break;

          st.pos.pop_front();
        }

        ans = max(ans, (int)st.pos.size() + k);

        if (ans >= n) {
          ans = n;
          break;
        }
      }

      if (ans == n) break;
    }

    cout << ans << '\n';
  }

  return 0;
}
