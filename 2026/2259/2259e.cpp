/*!
 * author: manhhomienbienthuy
 * created: 2026-09-06T11:12:01+00:00
 * https://codeforces.com/contest/2259/problem/E
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

    vector<int> b(n);
    for (int& x : b) cin >> x;

    vector<int> d(n + 1);

    for (int i = 0; i < n; i++) {
      if (b[i] <= 0) continue;

      int l = max(0, i - b[i] + 1), r = min(n, i + b[i]);
      d[l]++;
      d[r]--;
    }

    string ans(n, '0');
    int s = 0;
    bool ok = false;

    for (int i = 0; i < n; i++) {
      s += d[i];
      if (!s) {
        ans[i] = '1';
        ok = true;
      }
    }

    for (int i = 0; ok && i < n; i++) {
      if (b[i] == -1) continue;

      bool l = (i >= b[i]) && (ans[i - b[i]] == '1'),
           r = (i + b[i] < n && ans[i + b[i]] == '1');

      ok = ok && (l || r);
    }

    cout << (ok ? ans : "-1") << '\n';
  }

  return 0;
}
