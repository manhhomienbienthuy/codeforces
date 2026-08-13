/*!
 * author: manhhomienbienthuy
 * created: 2026-08-13T02:28:52+00:00
 * https://codeforces.com/gym/106642/problem/N
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  char t;

  cin >> n >> s >> t;

  auto fight = [](char a, char b) {
    if (a == b) return a;

    if ((a == 'R' && b == 'S') || (a == 'S' && b == 'P') ||
        (a == 'P' && b == 'R')) {
      return a;
    }

    return b;
  };

  vector<char> pref(n), suf(n);

  pref[0] = s[0];
  for (int i = 1; i < n; i++) {
    pref[i] = fight(pref[i - 1], s[i]);
  }

  suf[n - 1] = s[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = fight(suf[i + 1], s[i]);
  }

  int ans = 0;

  for (int i = 0; i + 1 < n; i++) ans += fight(pref[i], suf[i + 1]) == t;

  cout << ans << '\n';

  return 0;
}
