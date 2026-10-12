/*!
 * author: manhhomienbienthuy
 * created: 2026-10-10T15:56:22+00:00
 * https://codeforces.com/contest/2271/problem/E
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

    vector<int> cnt(n + 1);

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }

    auto check = [&](int x) {
      if (!k && !x) return false;

      vector<int> cnt2 = cnt;

      int mx_reach = n + k + 2 * x, c = 0, used = 0;

      for (int i = n; i > 1; i--) {
        c += cnt2[i];

        int cap = mx_reach - i, need = max(0, c - cap);

        used += need;
        c -= need;

        cnt2[(i + 1) / 2] += 2 * need;

        if (used > x) return false;
      }

      return true;
    };

    int l = 0, r = n;

    while (l <= r) {
      int mid = (l + r) >> 1;

      if (check(mid))
        r = mid - 1;
      else
        l = mid + 1;
    }

    cout << n + 2 * l << '\n';
  }

  return 0;
}
