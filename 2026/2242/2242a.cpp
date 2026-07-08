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
    bool ok = false;
    int cnt = 0;
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      cnt += x > 1;
      ok = ok || (x > 2) || (cnt > 1);
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
