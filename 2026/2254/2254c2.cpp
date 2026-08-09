/*!
 * author: manhhomienbienthuy
 * created: 2026-08-07T12:37:25+00:00
 * https://codeforces.com/contest/2254/problem/C2
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
    string a, b;
    cin >> n >> a >> b;

    int64_t ans = 0;
    deque<pair<int, bool>> dq;

    for (int i = 0; i < n; i += 2) {
      if (a[i] == '1' && b[i] == '0') {
        if (dq.empty() || dq.front().second)
          dq.push_back({i, true});
        else {
          ans += abs(i - dq.front().first) / 2;
          dq.pop_front();
        }
      } else if (a[i] == '0' && b[i] == '1') {
        if (dq.empty() || !dq.front().second)
          dq.push_back({i, false});
        else {
          ans += abs(i - dq.front().first) / 2;
          dq.pop_front();
        }
      }
    }

    if (!dq.empty()) {
      cout << -1 << '\n';
      continue;
    }

    for (int i = 1; i < n; i += 2) {
      if (a[i] == '1' && b[i] == '0') {
        if (dq.empty() || dq.front().second)
          dq.push_back({i, true});
        else {
          ans += abs(i - dq.front().first) / 2;
          dq.pop_front();
        }
      } else if (a[i] == '0' && b[i] == '1') {
        if (dq.empty() || !dq.front().second)
          dq.push_back({i, false});
        else {
          ans += abs(i - dq.front().first) / 2;
          dq.pop_front();
        }
      }
    }

    if (!dq.empty()) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans << '\n';
  }

  return 0;
}
