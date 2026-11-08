/*!
 * author: manhhomienbienthuy
 * created: 2026-11-07T15:49:45+00:00
 * https://codeforces.com/contest/2280/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, l;
    cin >> n >> l;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    sort(a.begin(), a.end());

    int64_t sum = 0;
    for (int x : a) sum += x;

    int64_t lim = l - 1;

    int64_t mx = (int64_t)sqrtl(lim);

    int64_t ans = a[n - 1], pref = 0;
    int p = 0;

    for (int x = 1; x <= mx; x++) {
      while (p < n - 1 && a[p] <= x) {
        pref += a[p];
        p++;
      }

      int64_t keep = pref;
      keep += 1LL * (n - 1 - p) * x;
      keep += min(0LL + a[n - 1], lim / x);

      ans = max(ans, keep);
    }

    cout << sum - ans << '\n';
  }

  return 0;
}
