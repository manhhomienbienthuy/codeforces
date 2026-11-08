/*!
 * author: manhhomienbienthuy
 * created: 2026-11-07T15:10:47+00:00
 * https://codeforces.com/contest/2280/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

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

    int mx = a[n - 1];

    vector<bool> exist(mx + 4, false);
    for (int x : a) exist[x] = true;

    vector prev(8, vector<int>(3));
    prev[0][0] = 1;

    for (int i = 1; i <= mx + 3; i++) {
      vector cur(8, vector<int>(3));

      int hi = i <= mx && exist[i];

      for (int mask = 0; mask < 8; mask++) {
        for (int cnt = 0; cnt <= 2; cnt++) {
          if (!prev[mask][cnt]) continue;

          for (int b = 0; b <= hi; b++) {
            int old = mask >> 2, sum = (mask >> 1 & 1) + (mask & 1) + b;

            int ncnt = cnt;

            if (old && sum != 2) ncnt++;

            if (ncnt > 2) continue;

            int nmask = ((mask << 1) & 7) | b;

            cur[nmask][ncnt] = (cur[nmask][ncnt] + prev[mask][cnt]) % MOD;
          }
        }
      }

      prev.swap(cur);
    }

    int ans = 0;

    for (int mask = 0; mask < 8; mask++) {
      for (int cnt = 0; cnt <= 2; cnt++) {
        ans = (ans + prev[mask][cnt]) % MOD;
      }
    }

    ans = (ans - 1 + MOD) % MOD;

    cout << ans << '\n';
  }

  return 0;
}
