/*!
 * author: manhhomienbienthuy
 * created: 2026-08-29T14:38:40+00:00
 * https://codeforces.com/contest/2258/problem/B1
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

    vector<int> cnt(m + 1);

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }

    vector<int> suf(m + 2);

    for (int i = m; i >= 1; i--) suf[i] = suf[i + 1] + cnt[i];

    int ans = 0;

    for (int d = 1; d <= m; d++) {
      int cur = suf[d] + (2 * d <= m ? cnt[2 * d] : 0);
      ans = max(ans, cur);
    }

    cout << ans << '\n';
  }

  return 0;
}
