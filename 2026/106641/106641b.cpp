/*!
 * author: manhhomienbienthuy
 * created: 2026-08-21T05:36:23+00:00
 * https://codeforces.com/gym/106641/problem/B
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

  int n, q, id = 0;
  cin >> n >> q;

  vector<int> read(n + 1);
  fenwick bit(q + 1);
  bit.add(0, n);

  while (q--) {
    int ops;
    cin >> ops;

    switch (ops) {
      case 1:
        id++;
        break;
      case 2:
        int f;
        cin >> f;
        bit.add(read[f], -1);
        bit.add(id, 1);
        read[f] = id;
        break;
      case 3:
        int s;
        cin >> s;
        cout << n - bit.sum(s - 1) << '\n';
        break;
    }
  }

  return 0;
}
