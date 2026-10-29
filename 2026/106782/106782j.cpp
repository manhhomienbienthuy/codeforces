/*!
 * author: manhhomienbienthuy
 * created: 2026-10-28T00:10:34+00:00
 * https://codeforces.com/gym/106782/problem/J
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, c;
  cin >> n >> c;

  vector<int> a(n);
  for (int& x : a) cin >> x;

  int64_t ans = 0;
  vector<int> sub(n + 1);

  for (int i = n - 1; i >= 0; i--) {
    if (a[i] > sub[i + 1]) {
      a[i] -= sub[i + 1];

      int t = (a[i] + c - 1) / c;
      ans += 2LL * (i + 1) * t;
      if (a[i] % c) sub[i] = c - (a[i] % c);
    } else {
      sub[i] = sub[i + 1] - a[i];
    }
  }

  cout << ans << '\n';

  return 0;
}
