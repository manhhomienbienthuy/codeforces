/*!
 * author: manhhomienbienthuy
 * created: 2026-06-30T04:59:18+00:00
 * https://codeforces.com/contest/2225/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int BASE = 91138233;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, l, k;
    cin >> n >> l >> k;
    string s;
    cin >> s;

    if (1ll * k * l > n) {
      cout << "NO\n";
      continue;
    }

    if (k == 1) {
      cout << "YES\n";
      cout << s << "\n";
      continue;
    }

    // rolling hash
    vector<int64_t> h(n + 1, 0), p(n + 1, 1);
    for (int i = 0; i < n; i++) {
      int x = s[i];
      h[i + 1] = (h[i] * BASE + x) % MOD;
      p[i + 1] = (p[i] * BASE) % MOD;
    }

    int limit = n - k * l;
    int result = 0;
    int result_len = l + limit;

    for (int i = l; i < n - l + 1; i++) {
      if (i % l > limit) continue;
      int cur_len = min(n - i, l + limit - (i % l));
      int cmp_len = min(result_len, cur_len);
      int lo = 0, hi = cmp_len;
      while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        int64_t ga = (h[result + mid] - h[result] * p[mid] % MOD + MOD) % MOD,
                gb = (h[i + mid] - h[i] * p[mid] % MOD + MOD) % MOD;
        if (ga == gb)
          lo = mid;
        else
          hi = mid - 1;
      }
      if ((lo < cmp_len && s[i + lo] > s[result + lo]) || lo == result_len) {
        result = i;
        result_len = cur_len;
      }
    }

    cout << "YES\n";
    cout << s.substr(result, result_len) << "\n";
  }
  return 0;
}
