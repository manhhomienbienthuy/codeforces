/*!
 * author: manhhomienbienthuy
 * created: 2026-08-08T04:40:35+00:00
 * https://codeforces.com/contest/2254/problem/D
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
    cin >> n;

    vector<int64_t> b(n);
    for (int64_t& x : b) cin >> x;

    vector<int64_t> c = b;
    sort(c.begin(), c.end());

    if (c[0] != 0) {
      cout << -1 << '\n';
      continue;
    }

    vector<pair<int64_t, int>> segs;

    for (int i = 0, j; i < n; i = j) {
      for (j = i + 1; j < n && c[j] == c[i]; j++);
      segs.push_back({c[i], j - i});
    }

    int64_t prev = 0;
    int64_t prev_len = segs[0].second;
    int64_t prev_val = 0;
    int64_t prev_sum = 0;

    vector<pair<int64_t, int64_t>> assign;

    bool ok = true;

    for (int i = 1; i < (int)segs.size(); i++) {
      auto [cur, cnt] = segs[i];

      if ((cur - prev_sum) % prev_len) {
        ok = false;
        break;
      }

      int64_t val = (cur - prev_sum) / prev_len;

      if (val <= prev_val) {
        ok = false;
        break;
      }

      assign.push_back({prev, val});

      prev_sum += val * prev_len;
      prev = cur;
      prev_len = cnt;
      prev_val = val;
    }

    if (!ok) {
      cout << -1 << '\n';
      continue;
    }

    assign.push_back({prev, prev_val + 1});

    for (int64_t x : b) {
      auto it = lower_bound(assign.begin(), assign.end(), make_pair(x, -1ll));

      cout << it->second << ' ';
    }
    cout << '\n';
  }

  return 0;
}
