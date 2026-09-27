/*!
 * author: manhhomienbienthuy
 * created: 2026-09-26T15:04:45+00:00
 * https://codeforces.com/contest/2269/problem/C
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

  int kth(int64_t k) {
    int pos = 0;

    int pw = 1;
    while ((pw << 1) <= n) pw <<= 1;

    for (; pw; pw >>= 1) {
      int nxt = pos + pw;

      if (nxt <= n && bit[nxt] < k) {
        k -= bit[nxt];
        pos = nxt;
      }
    }

    return pos;
  }
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
    fenwick fw(n);

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      fw.add(i, 1);
    }

    int64_t ans = 0;

    while (n >= k) {
      int l = fw.kth(k);
      int r = fw.kth(n - k + 1);

      int pos = a[l] >= a[r] ? l : r;

      ans += a[pos];
      fw.add(pos, -1);
      n--;
    }

    cout << ans << '\n';
  }

  return 0;
}
