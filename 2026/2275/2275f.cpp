/*!
 * author: manhhomienbienthuy
 * created: 2026-10-08T05:41:17+00:00
 * https://codeforces.com/contest/2275/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 1;
int spf[MAXN];

void init() {
  for (int i = 2; i < MAXN; i++) {
    if (!spf[i]) {
      spf[i] = i;
      for (int64_t j = 1LL * i * i; j < MAXN; j += i) {
        if (!spf[j]) spf[j] = i;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int mx = 0;
    vector<int> a(n), s(n);

    for (int& x : a) {
      cin >> x;
      mx = max(mx, x);
    }

    vector<int> cnt(mx + 1);

    for (int i = 0; i < n; i++) {
      int x = a[i], r = 1;

      while (x > 1) {
        int d = spf[x], odd = 0;

        while (!(x % d)) {
          x /= d;
          odd ^= 1;
        }

        if (odd) r *= d;
      }

      s[i] = r;
      cnt[r]++;
    }

    set<int> st;
    int64_t ans = 0;

    for (int i = 0; i < n; i++) {
      int x = s[i];

      while (x > 1) {
        int p = spf[x];

        if (st.count(p)) {
          st.erase(p);
        } else {
          st.insert(p);
        }

        x /= p;
      }

      int ker = 1;
      bool ok = true;

      for (int p : st) {
        if (ker > mx / p) {
          ok = false;
          break;
        }

        ker *= p;
      }

      if (ok) ans += cnt[ker];
    }

    cout << ans << '\n';
  }

  return 0;
}
