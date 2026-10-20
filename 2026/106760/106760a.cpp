/*!
 * author: manhhomienbienthuy
 * created: 2026-10-20T03:12:05+00:00
 * https://codeforces.com/gym/106760/problem/A
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

    vector<int> cnt(26);
    for (char c : s) cnt[c - 'a']++;

    int ans = 0;

    for (int i = 0; i < 26; i++) ans += cnt[i] - (cnt[i] & 1);

    cout << ans + ((n - ans) & 1) << '\n';
  }

  return 0;
}
