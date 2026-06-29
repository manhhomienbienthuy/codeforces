/*!
 * author: manhhomienbienthuy
 * created: 2026-06-28T23:47:40+00:00
 * https://codeforces.com/contest/2238/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, c;
    cin >> n >> c;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    bool ok = true;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < b[i]) ok = false;
      ans += a[i] - b[i];
    }
    if (ans < 0) {
      cout << -1 << '\n';
      continue;
    }

    if (!ok) {
      ans += c;
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      ok = true;
      for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
          ok = false;
          break;
        }
      }
    }
    if (!ok) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
    }
  }

  return 0;
}
