/*!
 * author: manhhomienbienthuy
 * created: 2026-10-07T00:45:29+00:00
 * https://codeforces.com/gym/106744/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int y;
  cin >> y;

  if (y == 2026) {
    cout << 4 << '\n';
    cout << "School Qual\nSchool Regional\nICPC Qual\nICPC Regional\n";
  } else if (y < 2019 || y == 2020 || y == 2021) {
    cout << 1 << '\n';
    cout << "ICPC Regional\n";
  } else {
    cout << 2 << '\n';
    cout << "ICPC Qual\nICPC Regional\n";
  }

  return 0;
}
