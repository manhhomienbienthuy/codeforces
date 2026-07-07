/*!
 * author: manhhomienbienthuy
 * created: 2026-07-06T14:34:32+00:00
 * https://codeforces.com/contest/2242/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    vector<int> c(k);
    for (auto& x : c) cin >> x;
    bool ok = false;
    int cnt = 0;
    for (auto x : c) {
      if (x > 2) {
        ok = true;
        break;
      }
      if (x > 1) cnt++;
      if (cnt > 1) {
        ok = true;
        break;
      }
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
