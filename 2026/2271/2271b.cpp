/*!
 * author: manhhomienbienthuy
 * created: 2026-10-10T15:14:39+00:00
 * https://codeforces.com/contest/2271/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> cnt(n + 1);

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }

    bool ok = false;

    for (int x = 0; x <= n; x++) {
      if (cnt[x] >= 2 * k) continue;

      ok = (cnt[x] == 2 * k - 1);
      break;
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
