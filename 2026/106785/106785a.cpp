/*!
 * author: manhhomienbienthuy
 * created: 2026-10-26T10:43:16+00:00
 * https://codeforces.com/gym/106785/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, a, b;

  cin >> n >> a >> b;

  cout << min(n * a, b) << '\n';

  return 0;
}
