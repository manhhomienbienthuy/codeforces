/*!
 * author: manhhomienbienthuy
 * created: 2026-07-15T01:04:38+00:00
 * https://codeforces.com/contest/2244/problem/E
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

    vector<int> pref(n, 0);
    for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + (s[i] == s[i - 1]);

    while (q--) {
      int l, r, k;
      cin >> l >> r >> k;
      bool ok = pref[r - 1] - pref[l - 1] <= 2 * k;
      cout << (ok ? "YES\n" : "NO\n");
    }
  }

  return 0;
}
