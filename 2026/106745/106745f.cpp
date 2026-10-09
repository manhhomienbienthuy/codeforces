/*!
 * author: manhhomienbienthuy
 * created: 2026-10-09T06:46:51+00:00
 * https://codeforces.com/gym/106745/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

bool is_square(int n) {
  int rt = int(sqrt(n));
  return rt * rt == n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    iota(a.begin(), a.end(), 1);

    for (int i = 0; i < n - 1; i++) {
      if (is_square(a[i] + a[i + 1])) swap(a[i - 1], a[i]);
    }

    for (auto x : a) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}
