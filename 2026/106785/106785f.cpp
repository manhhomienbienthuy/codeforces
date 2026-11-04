/*!
 * author: manhhomienbienthuy
 * created: 2026-11-04T01:03:31+00:00
 * https://codeforces.com/gym/106785/problem/F
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
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> pos_p(n + 1), pos_q(m + 1);

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      pos_p[x] = i;
    }

    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      pos_q[x] = i;
    }

    fenwick bit_p(n), bit_q(m);
    int lim = min(n, m), k;

    for (k = 1; k <= lim; k++) {
      bit_p.add(pos_p[k], 1);
      bit_q.add(pos_q[k], 1);

      if (bit_p.sum(pos_p[k]) != bit_q.sum(pos_q[k])) break;
    }

    cout << n + m - 2 * (k - 1) << '\n';
  }

  return 0;
}
