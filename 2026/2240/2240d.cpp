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
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int s = (int)a.size();
    for (int i = 0; i < s; i++) a.push_back(a[i]);

    vector<int64_t> pref(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }

    int64_t ans = 0;
    for (int i = n; i < 2 * n; i++) {
      int64_t left = pref[i] - pref[i - d];
      int64_t right = pref[i % n + d + 1] - pref[i % n + 1];
      int64_t neighbor = left + right;
      int64_t x = 2LL * d * a[i % n] - neighbor;
      if (x > 0) ans += x;
    }

    cout << ans << '\n';
  }

  return 0;
}
