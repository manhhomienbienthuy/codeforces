/*!
 * author: manhhomienbienthuy
 * created: 2026-10-09T07:00:24+00:00
 * https://codeforces.com/gym/106745/problem/B
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

    int64_t inv = 0;

    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) inv += a[i] > a[j];

    int64_t moves = inv + n / 2;

    cout << (moves & 1 ? "Alice" : "Bob") << '\n';
  }

  return 0;
}
