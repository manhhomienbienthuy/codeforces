/*!
 * author: manhhomienbienthuy
 * created: 2026-08-15T08:23:17+00:00
 * https://codeforces.com/gym/106644/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int& x : a) cin >> x;

  vector<int> z(n);

  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i < r) z[i] = min(r - i, z[i - l]);

    while (i + z[i] < n && a[z[i]] == a[i + z[i]]) z[i]++;

    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }

  int prev = -1;

  for (int k = 1; k < n; k++) {
    if ((z[k] < n - k)) prev = k;
    cout << prev << ' ';
  }
  cout << '\n';

  return 0;
}
