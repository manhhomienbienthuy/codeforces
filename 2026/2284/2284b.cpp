/*!
 * author: manhhomienbienthuy
 * created: 2026-11-06T14:44:23+00:00
 * https://codeforces.com/contest/2284/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    sort(a.begin(), a.end());

    int i = n - 1;
    while (a[i] == a[n - 1]) i--;

    if (k < n - 1 - i) {
      cout << "NO\n";
      continue;
    }

    int v = a[n - k];
    int r = int(upper_bound(a.begin(), a.end(), v) - a.begin());

    vector<int> ans;
    int first = k - (n - r);

    for (int i = 0; i < first; i++) ans.push_back(v);
    for (int i = r; i < n; i++) ans.push_back(a[i]);
    for (int i = r - first - 1; i >= 0; i--) ans.push_back(a[i]);

    cout << "YES\n";
    for (int x : ans) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}
