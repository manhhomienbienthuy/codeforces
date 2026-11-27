/*!
 * author: manhhomienbienthuy
 * created: 2026-11-27T07:21:27+00:00
 * https://codeforces.com/contest/2248/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> p(m);
    vector<int64_t> pref(m + 1);

    for (int i = 0; i < m; i++) {
      int r;
      cin >> p[i] >> r;
      pref[i + 1] = pref[i] + r;
    }

    if (!m) {
      cout << "NO\n";
      continue;
    }

    int64_t full = 1LL * n * d + pref[m];

    auto calc = [&](int k) {
      int blocks = k / n, rem = k % n;

      int idx = int(upper_bound(p.begin(), p.end(), rem) - p.begin());

      return 1LL * blocks * full + 1LL * rem * d + pref[idx];
    };

    vector<int64_t> val(m);
    for (int i = 0; i < m; i++) {
      val[i] = calc(p[i]);
    }

    bool ok = false;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        if (val[i] + val[j] > calc(p[i] + p[j] + 1)) {
          ok = true;
          break;
        }
      }

      if (ok) break;
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
