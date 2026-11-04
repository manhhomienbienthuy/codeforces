/*!
 * author: manhhomienbienthuy
 * created: 2026-11-04T08:32:52+00:00
 * https://codeforces.com/gym/106787/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string exp;
  cin >> exp;

  int add = (int)exp.find('+'), eq = (int)exp.find('=');

  string x = exp.substr(0, add), y = exp.substr(add + 1, eq - add - 1),
         z = exp.substr(eq + 1);

  int n = (int)x.size();

  vector<int> val(5);
  vector<bool> used(10);

  auto check = [&]() {
    int carry = 0;

    for (int i = n - 1; i >= 0; i--) {
      int dx = val[x[i] - 'a'], dy = val[y[i] - 'a'], dz = val[z[i] - 'a'];

      int sum = dx + dy + carry;

      if (sum % 10 != dz) {
        return false;
      }

      carry = sum / 10;
    }

    return carry == 0;
  };

  bool ok = false;

  for (val[0] = 0; val[0] < 10; val[0]++) {
    used[val[0]] = true;

    for (val[1] = 0; val[1] < 10; val[1]++) {
      if (used[val[1]]) continue;

      used[val[1]] = true;

      for (val[2] = 0; val[2] < 10; val[2]++) {
        if (used[val[2]]) continue;

        used[val[2]] = true;

        for (val[3] = 0; val[3] < 10; val[3]++) {
          if (used[val[3]]) continue;

          used[val[3]] = true;

          for (val[4] = 0; val[4] < 10; val[4]++) {
            if (used[val[4]]) continue;
            ok = check();
            if (ok) break;
          }

          used[val[3]] = false;
          if (ok) break;
        }

        used[val[2]] = false;
        if (ok) break;
      }

      used[val[1]] = false;
      if (ok) break;
    }

    used[val[0]] = false;
    if (ok) break;
  }

  if (!ok) {
    cout << "impossible\n";
  } else {
    for (int v : val) cout << v;
    cout << '\n';
  }

  return 0;
}
