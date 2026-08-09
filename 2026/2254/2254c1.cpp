/*!
 * author: manhhomienbienthuy
 * created: 2026-08-07T12:33:10+00:00
 * https://codeforces.com/contest/2254/problem/C1
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

    bool ok = true;

    for (int s = 0; ok && s < 2; s++) {
      int cnt = 0;

      for (int i = s; i < n; i += 2) {
        if (a[i] == '1' && b[i] == '0')
          cnt++;
        else if (a[i] == '0' && b[i] == '1')
          cnt--;
      }

      ok = !cnt;
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
