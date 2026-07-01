/*!
 * author: manhhomienbienthuy
 * created: 2026-07-01T02:02:03+00:00
 * https://codeforces.com/contest/2241/problem/D
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
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    int64_t s = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      s += a[i] - b[i];
      if (s > 0) {
        ok = false;
        break;
      }
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
