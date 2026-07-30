/*!
 * author: manhhomienbienthuy
 * created: 2026-07-30T02:04:37+00:00
 * https://codeforces.com/gym/106628/problem/B
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

    vector<int> a(2 * n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i + n] = a[i];
    }

    vector<int64_t> pref(2 * n + 1);
    for (int i = 0; i < 2 * n; i++) pref[i + 1] = pref[i] + a[i];

    deque<int> dq;

    for (int i = 1; i <= 2 * n; i++) {
      while (!dq.empty() && pref[dq.back()] >= pref[i]) {
        dq.pop_back();
      }

      dq.push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      while (!dq.empty() && dq.front() < i + 1) {
        dq.pop_front();
      }

      int64_t mn = pref[dq.front()];
      ans += mn >= pref[i];
    }

    cout << ans << '\n';
  }

  return 0;
}
