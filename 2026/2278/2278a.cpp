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

    if (n < m + 3) {
      cout << "NO\n";
    } else {
      vector<int> cnt(26);

      for (int i = 0; i < n; i++) cnt[p[i] - 'a']++;
      for (int i = 0; i < m; i++) cnt[q[i] - 'a']--;

      bool ok = (cnt['s' - 'a'] == 1) && (cnt['i' - 'a'] == 1) &&
                (cnt['x' - 'a'] == 1);
      if (ok) {
        for (int i = 0; i < 26; i++) {
          if (i != 's' - 'a' && i != 'i' - 'a' && i != 'x' - 'a' && cnt[i]) {
            ok = false;
            break;
          }
        }
      }

      cout << (ok ? "YES\n" : "NO\n");
    }
  }

  return 0;
}
