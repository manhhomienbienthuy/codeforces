/*!
 * author: manhhomienbienthuy
 * created: 2026-11-04T14:54:22+00:00
 * https://codeforces.com/contest/2283/problem/B
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

    int mx = 0;

    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        cnt += (a[j] % a[i] == 0);
      }

      mx = max(mx, cnt);
    }

    cout << n - mx << '\n';
  }

  return 0;
}
