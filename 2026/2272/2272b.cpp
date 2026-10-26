/*!
 * author: manhhomienbienthuy
 * created: 2026-10-26T14:50:41+00:00
 * https://codeforces.com/contest/2272/problem/B
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

    string s1, s2;
    cin >> s1 >> s2;

    int cnt = 0;

    for (int i = 0; i < n; i++) {
      cnt += s1[i] == 'f';
      cnt += s2[i] == 'f';
    }

    cout << (cnt & 1) << '\n';
  }

  return 0;
}
