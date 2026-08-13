/*!
 * author: manhhomienbienthuy
 * created: 2026-08-13T05:07:53+00:00
 * https://codeforces.com/gym/106642/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

struct state {
  int or_val, and_val;
  int64_t cnt;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;

  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;

    int msk = (1 << m) - 1;

    vector<int> a(n);
    for (int& x : a) {
      cin >> x;
      x &= msk;
    }

    int64_t ans = 0;

    vector<state> prev;

    for (int x : a) {
      vector<state> cur;
      cur.push_back({x, x, 1});

      for (auto& s : prev) {
        int nxt_or = s.or_val | x;
        int nxt_and = s.and_val & x;

        if (cur.back().or_val == nxt_or && cur.back().and_val == nxt_and) {
          cur.back().cnt += s.cnt;
        } else {
          cur.push_back({nxt_or, nxt_and, s.cnt});
        }
      }

      for (auto& s : cur) {
        if (__builtin_popcount(s.or_val ^ s.and_val) == k) ans += s.cnt;
      }

      prev = move(cur);
    }

    cout << ans << '\n';
  }

  return 0;
}
