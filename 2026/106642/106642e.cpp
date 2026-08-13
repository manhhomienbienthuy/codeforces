/*!
 * author: manhhomienbienthuy
 * created: 2026-08-13T02:00:59+00:00
 * https://codeforces.com/gym/106642/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> r(n);
  for (int& x : r) cin >> x;

  bool ok = false;

  for (int s = 0; !ok && s < 2; s++) {
    int cur = s;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
      cur += 1 - r[i];

      if (cur < 0 || cur > 1) break;

      cnt += cur;
    }

    if (cur != s) continue;

    ok = 0 < cnt && cnt < n;
  }

  cout << (ok ? "YES\n" : "NO\n");

  return 0;
}
