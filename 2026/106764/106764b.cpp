/*!
 * author: manhhomienbienthuy
 * created: 2026-10-21T07:30:20+00:00
 * https://codeforces.com/gym/106764/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int& x : a) cin >> x;

  sort(a.begin(), a.end());

  for (int i = 1; i < n; i++) {
    int cost = (a[i] - a[i - 1]) * i;

    if (cost > k) {
      cout << a[i - 1] + k / i << '\n';
      return 0;
    }

    k -= cost;
  }

  cout << a[n - 1] + k / n << '\n';

  return 0;
}
