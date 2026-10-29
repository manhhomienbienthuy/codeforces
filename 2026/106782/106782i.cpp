/*!
 * author: manhhomienbienthuy
 * created: 2026-10-27T11:58:38+00:00
 * https://codeforces.com/gym/106782/problem/I
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

  int ans = 0;

  for (int i = 0, j; i < n; i = j) {
    for (j = i + 1; j < n && a[j] == a[i]; j++);

    ans += (j - i) / 2;
  }

  cout << ans << '\n';

  return 0;
}
