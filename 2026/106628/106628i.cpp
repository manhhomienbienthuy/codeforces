/*!
 * author: manhhomienbienthuy
 * created: 2026-07-30T03:02:26+00:00
 * https://codeforces.com/gym/106628/problem/I
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

    vector<int> cnt(32, 0);

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[32 - __builtin_clz(x)]++;
    }

    int64_t ans = 0;

    for (int c : cnt) {
      if (c) ans += 1LL * c * (c - 1) / 2;
    }

    cout << ans << '\n';
  }

  return 0;
}
