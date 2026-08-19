/*!
 * author: manhhomienbienthuy
 * created: 2026-08-18T01:31:39+00:00
 * https://codeforces.com/contest/2257/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<bool> exist(26, false);

    while (n--) {
      string s;
      cin >> s;
      exist[s[0] - 'a'] = true;
    }

    bool ok = true;

    while (m--) {
      string s;
      cin >> s;
      for (char c : s) ok = ok && exist[c - 'A'];
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
