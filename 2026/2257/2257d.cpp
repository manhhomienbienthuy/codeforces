/*!
 * author: manhhomienbienthuy
 * created: 2026-08-18T09:43:14+00:00
 * https://codeforces.com/contest/2257/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int64_t S;
    int q;
    cin >> S >> q;

    vector<int64_t> div = {0};
    for (int64_t i = 1; i * i <= S; i++) {
      if (S % i == 0) {
        div.push_back(i);
        if (i != S / i) div.push_back(S / i);
      }
    }
    sort(div.begin(), div.end());
    int k = (int)div.size();

    vector<int64_t> pref(k);

    for (int i = 1; i < k; i++)
      pref[i] = pref[i - 1] + (div[i] - div[i - 1]) * (S / div[i]);

    while (q--) {
      int64_t x, y;
      cin >> x >> y;

      int r = (int)(lower_bound(div.begin(), div.end(), y) - div.begin()),
          l = (int)(upper_bound(div.begin(), div.end(), S / x) - div.begin()) -
              1;

      if (r <= l) {
        cout << x * y << '\n';
      } else {
        int64_t left = x * div[l], mid = pref[r - 1] - pref[l],
                right = (y - div[r - 1]) * (S / div[r]);

        cout << left + mid + right << '\n';
      }
    }
  }

  return 0;
}
