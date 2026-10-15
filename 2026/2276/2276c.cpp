/*!
 * author: manhhomienbienthuy
 * created: 2026-10-14T14:55:42+00:00
 * https://codeforces.com/contest/2276/problem/C
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

    vector<int> pref(n + 1);

    for (int i = 0; i < n; i++) pref[i + 1] = (pref[i] + a[i]) % k;

    int64_t ans = 0;
    vector<int> cnt(k);

    for (int r = k + 1; r <= n; r++) {
      int l = r - k - 1;

      cnt[pref[l]]++;

      ans += cnt[pref[r]];
    }

    cout << ans << '\n';
  }

  return 0;
}
