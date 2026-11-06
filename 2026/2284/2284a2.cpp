/*!
 * author: manhhomienbienthuy
 * created: 2026-11-06T14:40:26+00:00
 * https://codeforces.com/contest/2284/problem/A2
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

    sort(a.begin(), a.end(), greater<>());

    int64_t x = 0, y = 0;

    for (int v : a) {
      int64_t u = 1LL << v;

      if (x < y)
        x += u;
      else
        y += u;
    }

    cout << x * y << '\n';
  }

  return 0;
}
