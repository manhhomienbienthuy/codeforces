/*!
 * author: manhhomienbienthuy
 * created: 2026-11-06T01:43:45+00:00
 * https://codeforces.com/gym/106787/problem/G
 */

#include <bits/stdc++.h>
using namespace std;

struct point {
  int64_t x, y;

  bool operator<(const point& o) const {
    return x < o.x || (x == o.x && y < o.y);
  }

  bool operator==(const point& o) const { return x == o.x && y == o.y; }
};

int64_t cross(point a, point b, point c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  int64_t m;
  cin >> n >> m;

  vector<point> p(n);

  for (auto& [x, y] : p) cin >> x >> y;

  int64_t x0 = -1, mn_y = INT64_MAX;

  for (auto [x, y] : p) {
    if (y < mn_y || (y == mn_y && x > x0)) {
      mn_y = y;
      x0 = x;
    }
  }

  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());

  vector<point> hull;

  for (point pt : p) {
    while (hull.size() >= 2 &&
           cross(hull[hull.size() - 2], hull.back(), pt) <= 0) {
      hull.pop_back();
    }

    hull.push_back(pt);
  }

  int low = (int)hull.size();

  for (int i = (int)p.size() - 2; i >= 0; i--) {
    while ((int)hull.size() > low &&
           cross(hull[hull.size() - 2], hull.back(), p[i]) <= 0) {
      hull.pop_back();
    }

    hull.push_back(p[i]);
  }

  hull.pop_back();

  long double per = 0;

  for (int i = 0; i < (int)hull.size(); i++) {
    point a = hull[i], b = hull[(i + 1) % hull.size()];
    long double dx = b.x - a.x, dy = b.y - a.y;
    per += sqrtl(dx * dx + dy * dy);
  }

  int64_t ans = (int64_t)floorl((m - x0) / per) + 1;

  cout << ans << '\n';
  return 0;
}
