/*!
 * author: manhhomienbienthuy
 * created: 2026-10-24T11:04:42+00:00
 * https://codeforces.com/contest/2277/problem/A
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

    int ans = 0, pref = 0;
    bool ok = true;

    for (int i = 0; i <= n; i++) {
      pref += cnt[i] - k;
      if (!cnt[i] || pref < 0) {
        ans = i;
        ok = false;
        break;
      }
    }

    cout << (ok ? n + 1 : ans) << '\n';
  }

  return 0;
}
