/*!
 * author: manhhomienbienthuy
 * created: 2026-11-07T14:35:24+00:00
 * https://codeforces.com/contest/2280/problem/A
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

    int odd1 = 0, odd2 = 0;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      odd1 += x & 1;
    }

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      odd2 += x & 1;
    }

    if (k & 1) {
      cout << (odd1 <= odd2 ? "YES\n" : "NO\n");
    } else {
      cout << (odd1 >= odd2 ? "YES\n" : "NO\n");
    }
  }

  return 0;
}
