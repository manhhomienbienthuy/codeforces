/*!
 * author: manhhomienbienthuy
 * created: 2026-10-22T06:46:26+00:00
 * https://codeforces.com/gym/106764/problem/D
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

  int l = 0, r = n - 1;

  while (l < n - 1 && a[l + 1] <= a[l]) l++;
  while (r > 0 && a[r - 1] >= a[r]) r--;

  if (l >= r) {
    cout << 0 << '\n';
    return 0;
  }

  int ans = min(n - l - 1, r);

  for (int j = n - 1; j >= r; j--) {
    int i = int(upper_bound(a.begin(), a.begin() + l + 1, a[j], greater<>()) -
                a.begin());
    ans = min(ans, j - i);
  }

  cout << ans << '\n';
  return 0;
}
