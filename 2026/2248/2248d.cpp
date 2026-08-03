/*!
 * author: manhhomienbienthuy
 * created: 2026-08-03T00:45:42+00:00
 * https://codeforces.com/contest/2248/problem/D
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
    cin >> n >> q;

    string s, tt;
    cin >> s >> tt;

    vector<int> pref_s(n + 1, 0), pref_t(n + 1, 0), common(n + 1, 0);

    for (int i = 0; i < n; i++) {
      pref_s[i + 1] = pref_s[i] + (s[i] == '0');
      pref_t[i + 1] = pref_t[i] + (tt[i] == '0');
      common[i + 1] = common[i] + (s[i] == tt[i]);
    }

    while (q--) {
      int l, r;
      cin >> l >> r;

      int ns = pref_s[r] - pref_s[l - 1], nt = pref_t[r] - pref_t[l - 1],
          cm = common[r] - common[l - 1];

      cout << (abs(ns - nt) <= cm ? "YES\n" : "NO\n");
    }
  }

  return 0;
}
