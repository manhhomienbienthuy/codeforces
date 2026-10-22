/*!
 * author: manhhomienbienthuy
 * created: 2026-10-21T07:17:59+00:00
 * https://codeforces.com/gym/106764/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> s(n), a(m);
  for (int& x : s) cin >> x;
  for (int& x : a) cin >> x;

  sort(s.begin(), s.end());
  sort(a.begin(), a.end());

  int l = -1, ans = 0;

  for (int i = 0; i < m; i++) {
    for (l++; l < n && s[l] < a[i]; l++);

    if (l == n) break;

    ans++;
  }

  cout << ans << '\n';

  return 0;
}
