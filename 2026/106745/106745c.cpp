/*!
 * author: manhhomienbienthuy
 * created: 2026-10-09T08:51:12+00:00
 * https://codeforces.com/gym/106745/problem/C
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

    vector<int> a(n);
    for (int& x : a) cin >> x;

    if (n == 1) {
      cout << 0;
    } else if (n == 2) {
      int d = abs(a[0] - a[1]) % 4;
      cout << min(d, 4 - d);
    } else {
      int s = 0;
      for (int x : a) s ^= abs(x) & 1;
      cout << (!(n & 1) && s);
    }

    cout << '\n';
  }

  return 0;
}
