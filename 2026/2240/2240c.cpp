/*!
 * author: manhhomienbienthuy
 * created: 2026-06-28T06:23:16+00:00
 * https://codeforces.com/contest/2240/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, cnt = 0, all = 0;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) {
      cin >> x;
      cnt += x > 0;
      all ^= x;
    }

    if (cnt < 2) {
      cout << 0 << "\n";
      continue;
    }

    cnt = 0;
    for (auto x : a) cnt += (all ^ x) < x;
    cout << max(cnt, 1) << "\n";
  }

  return 0;
}
