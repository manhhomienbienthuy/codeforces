/*!
 * author: manhhomienbienthuy
 * created: 2026-08-09T01:15:45+00:00
 * https://codeforces.com/contest/2252/problem/A
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

    vector<int> a(n);
    int s = 0;
    for (int& x : a) {
      cin >> x;
      s += x;
    }

    sort(a.begin(), a.end());

    int max_freq = 0, max_val = 0;

    int cur = a[0], cnt = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] == cur)
        cnt++;
      else {
        if (cnt > max_freq) {
          max_freq = cnt;
          max_val = cur;
        }

        cnt = 1;
        cur = a[i];
      }
    }

    if (cnt > max_freq) {
      max_freq = cnt;
      max_val = cur;
    }

    int r = max(0, max_freq - (n - max_freq) - 2);

    cout << s - r * max_val << '\n';
  }

  return 0;
}
