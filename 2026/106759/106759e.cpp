/*!
 * author: manhhomienbienthuy
 * created: 2026-10-19T02:48:55+00:00
 * https://codeforces.com/gym/106759/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, T;
    cin >> n >> T;

    vector<int64_t> a;

    for (int i = 0; i < n; i++) {
      int64_t x;
      cin >> x;
      if (x) a.push_back(x);
    }

    sort(a.begin(), a.end());

    int64_t ans = 0;
    bool ok = true;

    for (int64_t x : a) {
      x += ans;

      if (x > T) {
        ok = false;
        break;
      }

      ans += x;
    }

    cout << (ok ? ans : -1) << '\n';
  }

  return 0;
}
