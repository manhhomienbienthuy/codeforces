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

    vector<int> suf_cnt(m + 2), suf_max(m + 2);

    for (int i = m; i >= 1; i--) {
      suf_cnt[i] = suf_cnt[i + 1] + cnt[i];
      suf_max[i] = max(suf_max[i + 1], cnt[i]);
    }

    int ans = 0;

    for (int d = 1; d <= m; d++) {
      int cur = cnt[d] + suf_cnt[d + 1];
      if (2 * d <= m) cur += cnt[2 * d];
      ans = max(ans, cur);

      ans = max(ans, cnt[d] + suf_max[d + 1]);
    }

    cout << ans << '\n';
  }

  return 0;
}
