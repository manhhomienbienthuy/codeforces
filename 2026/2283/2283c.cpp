/*!
 * author: manhhomienbienthuy
 * created: 2026-11-04T14:58:44+00:00
 * https://codeforces.com/contest/2283/problem/C
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

    vector<int> base(32), rep(32), ids;

    for (int i = 1; i <= n; i++) {
      int x = i ^ (i << 1);
      int64_t mask = 0;

      for (int b = 30; b >= 0; b--) {
        if (!(x >> b & 1)) continue;

        if (base[b]) {
          x ^= base[b];
          mask ^= rep[b];
        } else {
          int id = (int)ids.size();
          ids.push_back(i);

          mask ^= 1LL << id;
          base[b] = x;
          rep[b] = (int)mask;
          break;
        }
      }
    }

    auto pref = [](int n) {
      if (n % 4 == 0) return n;
      if (n % 4 == 1) return 1;
      if (n % 4 == 2) return n + 1;
      return 0;
    };

    int q;
    for (q = 0; (1 << q) <= n; q++);

    int k = (1 << q) - 1, org = pref(n);

    int64_t ans = 0;
    bool ok = false;

    for (int target : {2 * k, 2 * k + 1}) {
      int x = org ^ target;
      int64_t mask = 0;

      for (int b = 30; b >= 0; b--) {
        if (!(x >> b & 1)) continue;

        if (!base[b]) break;

        x ^= base[b];
        mask ^= rep[b];
      }

      if (!x) {
        ans = mask;
        ok = true;
        break;
      }
    }

    vector<int> d(n + 1);

    if (ok) {
      for (int i = 0; i < (int)ids.size(); i++) {
        if (ans >> i & 1) d[ids[i]] = 1;
      }
    }

    for (int i = 1; i <= n; i++) cout << d[i] << ' ';
    cout << '\n';
  }

  return 0;
}
