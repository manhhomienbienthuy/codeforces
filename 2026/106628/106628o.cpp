/*!
 * author: manhhomienbienthuy
 * created: 2026-07-30T05:53:18+00:00
 * https://codeforces.com/gym/106628/problem/O
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  // cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int64_t> pref(n + 1, 0);

    for (int i = 2; i <= n; i++) {
      cout << "? " << i;
      for (int j = 1; j <= i; j++) cout << ' ' << j;
      cout << '\n';

      cin >> pref[i];
    }

    vector<int64_t> d(n + 1);

    for (int i = 2; i <= n; i++) d[i] = pref[i] - pref[i - 1];

    vector<int> p(n + 1);

    vector<int> a(n);
    iota(a.begin(), a.end(), 1);

    for (int i = n; i >= 1; i--) {
      int ord = i - d[i];

      p[i] = a[ord - 1];
      a.erase(next(a.begin(), ord - 1));
    }

    cout << "!";
    for (int i = 1; i <= n; i++) cout << ' ' << p[i];
    cout << '\n';
  }

  return 0;
}
