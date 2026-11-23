/*!
 * author: manhhomienbienthuy
 * created: 2026-11-23T04:08:45+00:00
 * https://codeforces.com/contest/2289/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

struct fenwick {
  int n;
  vector<int64_t> bit;

  fenwick(int n) : n(n), bit(n + 1, 0) {}

  void add(int i, int64_t v) {
    for (i++; i <= n; i += i & -i) bit[i] += v;
  }

  int64_t sum(int i) {
    int64_t r = 0;
    for (i++; i > 0; i -= i & -i) r += bit[i];
    return r;
  }

  int64_t query(int l, int r) {
    if (l > r) return 0;
    return sum(r) - sum(l - 1);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int64_t> pref(n + 1);
    bool ok = true;

    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
      ok = ok && (pref[i + 1] >= 0);
    }

    if (!ok) {
      cout << -1 << '\n';
      continue;
    }

    vector<int64_t> vals = pref;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = (int)vals.size();

    auto gid = [&](int64_t x) {
      return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin());
    };

    fenwick bit(m);
    int64_t ans = 0;

    for (int i = 1; i <= n; i++) {
      int idx = gid(pref[i]);
      ans += bit.query(idx + 1, m - 1);
      bit.add(idx, 1);
    }

    cout << ans << '\n';
  }

  return 0;
}
