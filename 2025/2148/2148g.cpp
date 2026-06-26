/*!
 * author: manhhomienbienthuy
 * created: 2026-06-26T07:58:34+00:00
 * https://codeforces.com/contest/2148/problem/G
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> d(N + 1);
  for (int i = 1; i <= N; i++)
    for (int j = i; j <= N; j += i) d[j].push_back(i);
  for (auto& x : d) reverse(x.begin(), x.end());

  int t;
  cin >> t;
  while (t--) {
    int n, g = 0;
    cin >> n;
    vector<int> a(n + 1, 0), cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
      int x, y = 0;
      cin >> x;
      for (int j : d[x]) {
        cnt[j]++;
        a[j] = max(a[j], y);
        y = max(y, cnt[j]);
      }
      g = __gcd(g, x);
      cout << a[g] << " ";
    }
    cout << "\n";
  }

  return 0;
}
