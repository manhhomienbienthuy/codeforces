/*!
 * author: manhhomienbienthuy
 * created: 2026-08-03T00:37:42+00:00
 * https://codeforces.com/contest/2248/problem/B
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

    vector<int> a(n), b(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    if (n < 2 * m) {
      cout << "NO\n";
      continue;
    }

    bool ok = true;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; ok && i < m; i++) {
      ok = (a[i] < b[i]) && (a[n - m + i] > b[i]);
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
