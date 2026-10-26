/*!
 * author: manhhomienbienthuy
 * created: 2026-10-26T14:50:41+00:00
 * https://codeforces.com/contest/2272/problem/B
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

    string s1, s2;
    cin >> s1 >> s2;

    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {
      cnt1 += s1[i] == 'f';
      cnt2 += s2[i] == 'f';
    }

    int hi = max(cnt1, cnt2), lo = min(cnt1, cnt2);

    int diff = hi - lo;

    if (!diff) {
      cout << 0 << '\n';
    } else {
      const string& s = cnt1 > cnt2 ? s1 : s2;

      int odd = 0, len = 0;

      for (int i = 0; i < n; i++) {
        if (s[i] == 'f') {
          len++;
        } else {
          odd += len & 1;
          len = 0;
        }
      }

      odd += len & 1;

      int match = (hi - odd) / 2, pairs = min(match, diff / 2);

      cout << diff - 2 * pairs << '\n';
    }
  }

  return 0;
}
