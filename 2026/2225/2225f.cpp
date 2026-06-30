/*!
 * author: manhhomienbienthuy
 * created: 2026-06-30T04:59:18+00:00
 * https://codeforces.com/contest/2225/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

struct rolling_hash {
  static const int MOD1 = 1000000007;
  static const int MOD2 = 1000000009;
  static const int BASE1 = 91138233;
  static const int BASE2 = 97266353;

  int n;
  vector<int> h1, h2, p1, p2;

  rolling_hash(const string& s) {
    n = (int)s.size();
    h1.assign(n + 1, 0);
    h2.assign(n + 1, 0);
    p1.assign(n + 1, 1);
    p2.assign(n + 1, 1);

    for (int i = 0; i < n; i++) {
      int x = s[i];
      h1[i + 1] = (1ll * h1[i] * BASE1 + x) % MOD1;
      h2[i + 1] = (1ll * h2[i] * BASE2 + x) % MOD2;
      p1[i + 1] = (1ll * p1[i] * BASE1) % MOD1;
      p2[i + 1] = (1ll * p2[i] * BASE2) % MOD2;
    }
  }

  pair<int, int> get(int l, int r) const {
    int x1 = (h1[r] - 1ll * h1[l] * p1[r - l] % MOD1 + MOD1) % MOD1;
    int x2 = (h2[r] - 1ll * h2[l] * p2[r - l] % MOD2 + MOD2) % MOD2;
    return {x1, x2};
  }
};

int lcp(const rolling_hash& rh, int a, int b, int maxLen) {
  int lo = 0, hi = maxLen;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (rh.get(a, a + mid) == rh.get(b, b + mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  return lo;
}

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

    int limit = n - k * l;

    rolling_hash rh(s);

    int result = 0;
    int result_len = l + limit;

    for (int i = l; i < n - l + 1; i++) {
      if (i % l > limit) continue;
      int cur_len = min(n - i, l + limit - (i % l));
      int cmpLen = min(result_len, cur_len);
      int c = lcp(rh, result, i, cmpLen);
      if ((c < cmpLen && s[i + c] > s[result + c]) ||
          (c == cmpLen && cur_len > result_len)) {
        result = i;
        result_len = cur_len;
      }
    }

    cout << "YES\n";
    cout << s.substr(result, result_len) << "\n";
  }
  return 0;
}
