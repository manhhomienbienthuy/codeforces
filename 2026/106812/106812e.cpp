/*!
 * author: manhhomienbienthuy
 * created: 2026-11-09T03:57:24+00:00
 * https://codeforces.com/gym/106812/problem/5
 */

#include <bits/stdc++.h>
using namespace std;

int n, k;
string x, y, z;
int8_t vis[10][2][1 << 10];

bool dfs(int pos, int carry, int mask) {
  int cnt = __builtin_popcount((unsigned)mask);

  if (cnt > k) return false;

  if (pos == n) return !carry && cnt == k;

  int8_t& mem = vis[pos][carry][mask];

  if (mem != -1) return mem;

  mem = 0;

  for (int a = 0; a <= 9; a++) {
    for (int b = 0; b <= 9; b++) {
      int sum = a + b + carry;
      int c = sum % 10, nc = sum / 10;

      if (n > 1 && pos == n - 1 && (!a || !b || !c)) continue;

      int nm = mask | (1 << a) | (1 << b) | (1 << c);

      if (dfs(pos + 1, nc, nm)) {
        int i = n - 1 - pos;

        x[i] = char('0' + a);
        y[i] = char('0' + b);
        z[i] = char('0' + c);

        return (mem = 1);
      }
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  x = y = z = string(n, '0');
  memset(vis, -1, sizeof(vis));

  if (!dfs(0, 0, 0)) {
    cout << "NO\n";
    return 0;
  }

  vector<char> mp(10);
  char nxt = 'A';

  auto conv = [&](const string& s) {
    string res;

    for (char ch : s) {
      int d = ch - '0';
      if (!mp[d]) mp[d] = nxt++;

      res += mp[d];
    }

    return res;
  };

  cout << conv(x) << '+' << conv(y) << '=' << conv(z) << '\n';
  cout << x << '+' << y << '=' << z << '\n';

  return 0;
}
