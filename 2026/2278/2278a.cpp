/*!
 * author: manhhomienbienthuy
 * created: 2026-10-31T15:08:00+00:00
 * https://codeforces.com/contest/2278/problem/A
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

    string p, q;
    cin >> p >> q;

    if (n != m + 3) {
      cout << "NO\n";
      continue;
    }

    vector<int> cnt(26);

    for (char c : p) cnt[c - 'a']++;
    for (char c : q) cnt[c - 'a']--;

    bool ok = true;

    for (int i = 0; i < 26; i++) {
      int x = (i == 8 || i == 18 || i == 23);
      if (cnt[i] != x) {
        ok = false;
        break;
      }
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
