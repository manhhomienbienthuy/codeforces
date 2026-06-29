/*!
 * author: manhhomienbienthuy
 * created: 2026-06-28T07:57:10+00:00
 * https://codeforces.com/contest/2240/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(2 * n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] = a[i + n] = x;
    }

    vector<int64_t> pref(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }

    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
      int64_t left = pref[i + n] - pref[i - d + n];
      int64_t right = pref[i + d + 1] - pref[i + 1];
      ans += max(0ll, 2ll * d * a[i % n] - left - right);
    }

    cout << ans << "\n";
  }

  return 0;
}
