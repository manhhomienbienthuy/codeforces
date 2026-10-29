/*!
 * author: manhhomienbienthuy
 * created: 2026-10-27T12:35:02+00:00
 * https://codeforces.com/gym/106782/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> q = {1, 1};
  q.reserve((1 << (n + 1)) - 2);

  for (int i = 2; i <= n; i++) {
    for (int& x : q) x++;
    q.push_back(1);
    q.insert(q.end(), q.begin(), q.end());
  }

  cout << ((1 << (n + 1)) - 2) << '\n';

  for (int x : q) cout << x << ' ';
  cout << '\n';

  return 0;
}
