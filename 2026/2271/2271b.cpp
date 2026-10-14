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

    vector<int> a(n);
    for (int& x : a) cin >> x;

    sort(a.begin(), a.end());

    bool ok = false;

    for (int i = 0, j, prev = -1; i < n; i = j, prev++) {
      if (a[i] != prev + 1) break;

      for (j = i + 1; j < n && a[j] == a[i]; j++);
      int l = j - i;

      if (l >= 2 * k) continue;

      ok = (l == 2 * k - 1);
      break;
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
