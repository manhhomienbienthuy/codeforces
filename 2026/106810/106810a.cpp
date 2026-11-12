/*!
 * author: manhhomienbienthuy
 * created: 2026-11-10T06:41:06+00:00
 * https://codeforces.com/gym/106810/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

struct rec {
  int64_t kx, ky, w;

  bool operator<(const rec& o) const {
    if (kx != o.kx) return kx < o.kx;
    return ky < o.ky;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int64_t> x(n), y(n), w(n);

    for (int64_t& v : x) cin >> v;
    for (int64_t& v : y) cin >> v;
    for (int64_t& v : w) cin >> v;

    vector<rec> v;

    for (int i = 0; i < n; i++) {
      int64_t ax = 1LL * a * x[i], by = 1LL * b * y[i], bx = 1LL * b * x[i],
              ay = 1LL * a * y[i];

      for (int j = 0; j < n; j++) {
        int64_t kx = x[j] - ax + by, ky = y[j] - bx - ay;
        v.push_back({kx, ky, w[i]});
      }
    }

    sort(v.begin(), v.end());

    int64_t ans = 0;
    int sz = (int)v.size();

    for (int l = 0, r; l < sz; l = r) {
      int64_t sum = 0;

      for (r = l; r < sz && v[r].kx == v[l].kx && v[r].ky == v[l].ky; r++) {
        sum += v[r].w;
      }

      ans = max(ans, sum);
    }

    cout << ans << '\n';
  }

  return 0;
}
