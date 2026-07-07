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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> cnt(n + 1, vector<int>(4, 0));
    for (int i = 1; i <= n; i++) {
      cnt[i] = cnt[i - 1];
      cnt[i][a[i]]++;
    }

    vector<int> D(n + 1), sfx(n + 2, INT_MIN);
    for (int i = 0; i <= n; i++) D[i] = cnt[i][1] + cnt[i][2] - cnt[i][3];
    for (int i = n - 1; i >= 1; i--) sfx[i] = max(sfx[i + 1], D[i]);

    bool ok = false;
    for (int i = 1; i <= n - 2 && !ok; i++) {
      if (cnt[i][1] >= cnt[i][2] + cnt[i][3]) {
        if (sfx[i + 1] >= D[i]) ok = true;
      }
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
