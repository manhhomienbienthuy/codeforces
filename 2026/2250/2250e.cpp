/*!
 * author: manhhomienbienthuy
 * created: 2026-07-27T06:28:14+00:00
 * https://codeforces.com/contest/2250/problem/E
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
    vector<int> p(2 * n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      p[i + n] = p[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
      bool ok = true;
      int segs = 0;

      vector<bool> used(n + 1, false);

      for (int j = i; j < i + n; j++) {
        int x = p[j];
        used[x] = true;
        segs++;

        if (x > 1 && used[x - 1]) segs--;
        if (x < n && used[x + 1]) segs--;

        if (segs > 2) {
          ok = false;
          break;
        }
      }

      ans += ok;
    }

    cout << ans << '\n';
  }

  return 0;
}
