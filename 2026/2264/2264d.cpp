/*!
 * author: manhhomienbienthuy
 * created: 2026-09-17T05:30:47+00:00
 * https://codeforces.com/contest/2264/problem/D
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

    if (n == 1) {
      cout << "1\n";
      continue;
    }

    if (n == 2) {
      cout << "11\n";
      continue;
    }

    n++;

    int q = n / 3, r = n % 3;

    vector<int> pos, len;

    if (r == 0) {
      if (q % 2 == 0) {
        len = {q, q, q};
      } else if (q != 1) {
        len = {q, 2, q, q - 2};
      }
    } else if (r == 1) {
      if (q % 2 == 0) {
        len = {q, q, q + 1};
      } else {
        len = {q, 2, q, q - 1};
      }
    } else {
      if (q % 2 == 0) {
        if (q == 0) {
        } else {
          len = {q, 2, q + 1, q - 1};
        }
      } else {
        len = {q + 1, 2, q, q - 1};
      }
    }

    int cur = 0;

    for (int i = 0; i + 1 < (int)len.size(); i++) {
      cur += len[i];
      if (cur <= n) pos.push_back(cur);
    }

    string s(n - 1, '0');

    for (int p : pos) {
      if (1 <= p && p <= n) s[p - 1] = '1';
    }

    cout << s << '\n';
  }

  return 0;
}
