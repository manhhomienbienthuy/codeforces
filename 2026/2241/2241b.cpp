/*!
 * author: manhhomienbienthuy
 * created: 2026-07-01T01:07:04+00:00
 * https://codeforces.com/contest/2241/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> g = {11,      101,      1001,      10001,     100001,
                   1000001, 10000001, 100000001, 1000000001};
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = (int)s.size();
    cout << g[n - 1] << '\n';
  }

  return 0;
}
