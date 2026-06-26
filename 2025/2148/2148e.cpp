/*!
 * author: manhhomienbienthuy
 * created: 2026-06-26T04:44:22+00:00
 * https://codeforces.com/contest/2148/problem/E
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
    vector<int> a(n), cnt(n + 1, 0), target(n + 1, 0);
    for (auto& x : a) {
      cin >> x;
      cnt[x]++;
    }

    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] % k) {
        ok = false;
        break;
      }
      target[i] = cnt[i] / k;
    }

    if (!ok) {
      cout << 0 << "\n";
      continue;
    }

    cnt.assign(n + 1, 0);
    int l = -1, r;
    int64_t ans = 0;
    for (r = 0; r < n; r++) {
      int x = a[r];
      cnt[x]++;
      if (cnt[x] > target[x]) {
        for (l = l + 1; a[l] != x; l++) cnt[a[l]]--;
        cnt[x]--;
      }
      ans += r - l;
    }
    cout << ans << "\n";
  }
  return 0;
}
