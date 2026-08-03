/*!
 * author: manhhomienbienthuy
 * created: 2026-07-30T13:15:13+00:00
 * https://codeforces.com/gym/106628/problem/K
 */

#include <bits/stdc++.h>
using namespace std;

struct Point {
  int64_t x, y;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<Point> pts(n);
    for (auto& p : pts) cin >> p.x >> p.y;

    if (n <= 3) {
      cout << 0 << '\n';
      continue;
    }

    vector<pair<int64_t, int>> max_a(3, {LLONG_MIN, -1}),
        min_a(3, {LLONG_MAX, -1});
    vector<pair<int64_t, int>> max_b(3, {LLONG_MIN, -1}),
        min_b(3, {LLONG_MAX, -1});

    auto update_max = [](vector<pair<int64_t, int>>& v, int64_t val, int i) {
      if (val > v[0].first) {
        v[2] = v[1];
        v[1] = v[0];
        v[0] = {val, i};
      } else if (val > v[1].first) {
        v[2] = v[1];
        v[1] = {val, i};
      } else if (val > v[2].first) {
        v[2] = {val, i};
      }
    };

    auto update_min = [](vector<pair<int64_t, int>>& v, int64_t val, int i) {
      if (val < v[0].first) {
        v[2] = v[1];
        v[1] = v[0];
        v[0] = {val, i};
      } else if (val < v[1].first) {
        v[2] = v[1];
        v[1] = {val, i};
      } else if (val < v[2].first) {
        v[2] = {val, i};
      }
    };

    for (int i = 0; i < n; i++) {
      int64_t a = pts[i].x + pts[i].y, b = pts[i].x - pts[i].y;
      update_max(max_a, a, i);
      update_min(min_a, a, i);
      update_max(max_b, b, i);
      update_min(min_b, b, i);
    }

    auto get_val = [](const vector<pair<int64_t, int>>& v, int r1,
                      int r2) -> int64_t {
      for (auto& [val, idx] : v)
        if (idx >= 0 && idx != r1 && idx != r2) return val;
      return 0;
    };

    auto calc = [&](int r1, int r2) -> int64_t {
      int rem = n - (r1 >= 0) - (r2 >= 0 && r2 != r1);
      if (rem <= 1) return 0;
      int64_t ma = get_val(max_a, r1, r2), na = get_val(min_a, r1, r2);
      int64_t mb = get_val(max_b, r1, r2), nb = get_val(min_b, r1, r2);
      return max(ma - na, mb - nb);
    };

    set<int> cs;
    for (int k = 0; k < 2; k++) {
      if (max_a[k].second >= 0) cs.insert(max_a[k].second);
      if (min_a[k].second >= 0) cs.insert(min_a[k].second);
      if (max_b[k].second >= 0) cs.insert(max_b[k].second);
      if (min_b[k].second >= 0) cs.insert(min_b[k].second);
    }

    vector<int> cv(cs.begin(), cs.end());
    int m = (int)cv.size();

    int64_t ans = calc(-1, -1);
    for (int i = 0; i < m; i++) {
      ans = min(ans, calc(cv[i], -1));
      for (int j = i + 1; j < m; j++) ans = min(ans, calc(cv[i], cv[j]));
    }

    cout << ans << '\n';
  }

  return 0;
}
