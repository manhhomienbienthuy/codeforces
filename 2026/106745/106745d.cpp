/*!
 * author: manhhomienbienthuy
 * created: 2026-10-10T01:13:58+00:00
 * https://codeforces.com/gym/106745/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

const int LIM = 20000;
const int OFFSET = LIM;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n), b(n), d(n);

    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    for (int i = 0; i < n; i++) d[i] = a[i] - b[i];

    bitset<2 * LIM + 1> dp;
    dp[OFFSET] = 1;

    int ans = 0;

    for (int i = 1; i < n; i++) {
      int diff = d[i] - d[i - 1];

      if (diff == 0) continue;

      ans++;

      if (diff > 0) {
        dp |= dp << diff;
      } else {
        dp |= dp >> -diff;
      }
    }

    int64_t pos = OFFSET - d[0];

    bool ok = 0 <= pos && pos <= 2 * LIM && dp[(int)pos];

    cout << ans + !ok << '\n';
  }

  return 0;
}
