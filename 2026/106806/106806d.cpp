/*!
 * author: manhhomienbienthuy
 * created: 2026-11-12T01:31:05+00:00
 * https://codeforces.com/gym/106806/problem/D
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

  sort(a.begin(), a.end());

  int64_t pref = a[0];

  for (int i = 1; i < n; i++) {
    if (a[i] <= pref) {
      cout << "possible\n";
      return 0;
    }

    pref += a[i];
  }

  cout << "impossible\n";

  return 0;
}
