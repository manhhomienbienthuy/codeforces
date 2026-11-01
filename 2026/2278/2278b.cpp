/*!
 * author: manhhomienbienthuy
 * created: 2026-10-31T15:13:24+00:00
 * https://codeforces.com/contest/2278/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    vector<int> a(3), ans(3);
    cin >> a[0] >> a[1] >> a[2];

    int n = a[0] + a[1] + a[2];

    int it = int(max_element(a.begin(), a.end()) - a.begin());
    ans[(it + 2) % 3] = n;

    string s = "RSP";
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < ans[i]; j++) cout << s[i];
    }
    cout << '\n';
  }

  return 0;
}
