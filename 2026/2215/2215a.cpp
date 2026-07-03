/*!
 * author: manhhomienbienthuy
 * created: 2026-07-03T02:13:00+00:00
 * https://codeforces.com/contest/2215/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k, p, q;
    cin >> n >> k >> p >> q;

    vector<int> a(n), calc_p(n), calc_q(n), calc(n);
    int64_t sp = 0, sq = 0, sm = 0, s = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      calc_p[i] = a[i] % p % q;
      calc_q[i] = a[i] % q % p;
      calc[i] = min(calc_p[i], calc_q[i]);
      s += calc[i];

      if (i < k) {
        sp += calc_p[i];
        sq += calc_q[i];
        sm += calc[i];
      }
    }

    int64_t wdiff = min(sp - sm, sq - sm);
    for (int i = k; i < n; i++) {
      sp = sp - calc_p[i - k] + calc_p[i];
      sq = sq - calc_q[i - k] + calc_q[i];
      sm = sm - calc[i - k] + calc[i];
      wdiff = min({wdiff, sp - sm, sq - sm});
    }

    cout << s + wdiff << '\n';
  }

  return 0;
}
