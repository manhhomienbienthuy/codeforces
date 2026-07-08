/*!
 * author: manhhomienbienthuy
 * created: 2026-07-06T14:41:36+00:00
 * https://codeforces.com/contest/2242/problem/B
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
    vector<vector<int>> cnt(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (i > 0) cnt[i] = cnt[i - 1];
      cnt[i][x - 1]++;
    }

    vector<int> d(n), suf(n, INT_MIN);
    for (int i = 0; i < n; i++) d[i] = cnt[i][0] + cnt[i][1] - cnt[i][2];
    for (int i = n - 2; i >= 0; i--) suf[i] = max(suf[i + 1], d[i]);

    bool ok = false;
    for (int i = 0; i < n - 2 && !ok; i++) {
      if (cnt[i][0] >= cnt[i][1] + cnt[i][2]) {
        if (suf[i + 1] >= d[i]) ok = true;
      }
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
