/*!
 * author: manhhomienbienthuy
 * created: 2026-06-25T01:42:33+00:00
 * https://codeforces.com/contest/2035/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int64_t prev = 0;
    vector<pair<int, int64_t>> s;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      int64_t p = 1;
      while (!(x & 1)) {
        p *= 2;
        x >>= 1;
      }
      bool flag = false;
      while (!s.empty()) {
        int u = s.back().first;
        int64_t v = s.back().second;
        if (!flag && x * p < u) break;
        p *= v;
        if (p > (1ll << 32)) {
          flag = true;
          p %= MOD;
        }
        prev = ((prev + u - u * v % MOD) % MOD + MOD) % MOD;
        s.pop_back();
      }
      s.push_back({x, p});

      prev = (prev + x * p % MOD) % MOD;
      cout << prev << " ";
    }
    cout << "\n";
  }

  return 0;
}
