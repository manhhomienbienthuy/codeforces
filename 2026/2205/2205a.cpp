/*!
 * author: manhhomienbienthuy
 * created: 2026-07-06T01:06:04+00:00
 * https://codeforces.com/contest/2205/problem/A
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
    for (auto& x : a) cin >> x;
    swap(a[0], a[max_element(a.begin(), a.end()) - a.begin()]);
    for (auto x : a) cout << x << " ";
    cout << '\n';
  }

  return 0;
}
