/*!
 * author: manhhomienbienthuy
 * created: 2026-10-07T09:02:41+00:00
 * https://codeforces.com/gym/106744/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int64_t calc(int n, const vector<int>& digits) {
  if (n == 0) return 1;

  string s = to_string(n);
  int len = (int)s.size(), d = (int)digits.size(), first = d - 1;

  vector<int64_t> pw(len + 1, 1);

  for (int i = 1; i <= len; i++) {
    pw[i] = pw[i - 1] * d;
  }

  int64_t ans = 1;

  for (int sz = 1; sz < len; sz++) {
    ans += 1LL * first * pw[sz - 1];
  }

  for (int i = 0; i < len; i++) {
    int cur = s[i] - '0';

    bool found = false;

    for (int x : digits) {
      if (i == 0 && x == 0) continue;

      if (x < cur) {
        ans += pw[len - i - 1];
      } else if (x == cur) {
        found = true;
        break;
      } else {
        break;
      }
    }

    if (!found) return ans;
  }

  return ans + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> normal = {0, 1, 5, 8}, turn = {0, 1, 3, 5, 7, 8};

  cout << calc(n, normal) << ' ' << calc(n, turn) << '\n';

  return 0;
}
