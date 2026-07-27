/*!
 * author: manhhomienbienthuy
 * created: 2026-07-26T04:48:59+00:00
 * https://codeforces.com/contest/2209/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, q;
    string s;
    cin >> n >> q >> s;

    while (q--) {
      int l, r;
      cin >> l >> r;
      l--;
      r--;

      int m = r - l + 1;

      int64_t ans = 0;

      vector<int> pi(m), g(m), h(m);

      for (int i = 0, j = 0; i < m; i++) {
        if (i == 0) {
          pi[i] = 0;
        } else {
          while (j > 0 && s[l + i] != s[l + j]) {
            j = pi[j - 1];
          }

          if (s[l + i] == s[l + j]) {
            j++;
          }

          pi[i] = j;
        }

        if (pi[i] == 0) {
          g[i] = i + 1;
          h[i] = 1;
        } else {
          g[i] = g[pi[i] - 1];
          h[i] = h[i - g[i]] + 1;
        }

        ans += h[i];
      }

      cout << ans << '\n';
    }
  }

  return 0;
}
