/*!
 * author: manhhomienbienthuy
 * created: 2026-07-29T01:44:53+00:00
 * https://codeforces.com/contest/1993/problem/A
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
    string s;
    cin >> n >> s;

    vector<int> cnt(4, 0);
    for (int i = 0; i < 4 * n; i++) {
      if (s[i] != '?') {
        cnt[s[i] - 'A']++;
      }
    }

    int ans = 0;
    for (int c : cnt) ans += min(n, c);
    cout << ans << '\n';
  }

  return 0;
}
