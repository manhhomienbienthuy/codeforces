/*!
 * author: manhhomienbienthuy
 * created: 2026-09-07T01:15:09+00:00
 * https://codeforces.com/contest/2259/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

struct fenwick {
  int n;
  vector<int> bit;

  fenwick(int n) : n(n), bit(n + 1, 0) {}

  void add(int i, int v) {
    for (i++; i <= n; i += i & -i) bit[i] += v;
  }

  int sum(int i) {
    int r = 0;
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
    int n;
    cin >> n;

    vector<int> a(n);
    int k = 0;

    for (int& x : a) {
      cin >> x;
      k += x;
    }

    int z = n - k;

    string s;
    cin >> s;

    if (!k || !z) {
      for (int i = 0; i <= n; i++) cout << 0 << ' ';
      cout << '\n';
      continue;
    }

    vector<int> h(k);

    fenwick bit(z);

    int cnt = 0, idx = 0;
    int64_t ans = 1ll * k * z;

    for (int x : a) {
      if (!x)
        cnt++;
      else {
        ans -= cnt;
        h[idx] = cnt;
        bit.add(h[idx], 1);
        idx++;
      }
    }

    cout << ans << ' ';

    idx = 0;
    int add = 0;

    for (char c : s) {
      if (!ans) {
        cout << 0 << ' ';
        continue;
      }

      if (c == '0') {
        add++;
        ans -= bit.sum(z - add);
      } else {
        if (idx < k && h[idx] + add < z) {
          ans -= z - (h[idx] + add);
          bit.add(h[idx], -1);
          idx++;
        }
      }

      cout << ans << ' ';
    }

    cout << '\n';
  }

  return 0;
}
