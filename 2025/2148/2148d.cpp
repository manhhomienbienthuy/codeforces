/*!
 * author: manhhomienbienthuy
 * created: 2026-06-26T04:29:20+00:00
 * https://codeforces.com/contest/2148/problem/D
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
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x & 1)
        odd.push_back(x);
      else
        even.push_back(x);
    }
    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());
    if (!odd.size()) {
      cout << 0 << "\n";
      continue;
    }

    int64_t ans = odd[0] + accumulate(even.begin(), even.end(), 0ll);
    for (uint32_t i = 1; i < (odd.size() + 1) / 2; i++) {
      ans += odd[i];
    }
    cout << ans << "\n";
  }

  return 0;
}
