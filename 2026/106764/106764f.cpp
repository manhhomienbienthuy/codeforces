/*!
 * author: manhhomienbienthuy
 * created: 2026-10-23T08:01:17+00:00
 * https://codeforces.com/gym/106764/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

string s;

void move(int m, int fr, int to, int tmp) {
  if (m == -1) return;

  move(m - 1, fr, tmp, to);
  cout << fr << ' ' << to << '\n';
  move(m - 1, tmp, to, fr);
}

void solve(int m, int fr) {
  if (m == -1) return;

  int to = (s[m] == '0') ? 2 : 3;

  if (fr == to) {
    solve(m - 1, fr);
  } else {
    int tmp = 6 - fr - to;

    move(m - 1, fr, tmp, to);
    cout << fr << ' ' << to << '\n';
    solve(m - 1, tmp);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n >> s;

  reverse(s.begin(), s.end());

  solve(n - 1, 1);
  return 0;
}
