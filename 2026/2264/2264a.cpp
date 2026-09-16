/*!
 * author: manhhomienbienthuy
 * created: 2026-09-14T04:07:27+00:00
 * https://codeforces.com/contest/2264/problem/A
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

    vector<int> b;

    for (int i = 0; i < n; i++) {
      if (a[i] != i + 1) b.push_back(i);
    }

    int m = (int)b.size();
    bool ok = true;

    for (int i = 0; ok && i < m / 2; i++) {
      int l = b[i], r = b[m - i - 1];
      ok = (a[r] == l + 1) && (a[l] == r + 1);
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
