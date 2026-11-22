/*!
 * author: manhhomienbienthuy
 * created: 2026-11-21T15:16:25+00:00
 * https://codeforces.com/contest/2287/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e4 + 1;

int spf[MAX];

void spf_init() {
  for (int i = 2; i < MAX; i++) {
    if (!spf[i]) {
      spf[i] = i;
      for (int64_t j = 1ll * i * i; j < MAX; j += i)
        if (!spf[j]) spf[j] = i;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  spf_init();

  int t;
  cin >> t;

  vector<int> ans(t);
  vector<vector<pair<int, int>>> query(MAX);

  int mx_n = 0, mx_m = 0;

  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;

    mx_n = max(mx_n, n);
    mx_m = max(mx_m, m);
    query[m].push_back({n, i});
  }

  vector<char> is_square(mx_m + 1, true);
  is_square[0] = false;

  for (int i = 2; (int64_t)i * i <= mx_m; i++) {
    int sq = i * i;

    for (int j = sq; j <= mx_m; j += sq) {
      is_square[j] = false;
    }
  }

  vector<int> id(mx_m + 1, -1);
  int cnt = 0;

  for (int i = 1; i <= mx_m; i++) {
    if (is_square[i]) id[i] = cnt++;
  }

  int words = (mx_n >> 6) + 1;

  vector<uint64_t> c((size_t)cnt * words);
  vector<uint64_t> pre(words);

  for (int v = 1; v <= mx_m; v++) {
    vector<int> divs;
    divs.push_back(1);

    int x = v;

    while (x > 1) {
      int p = spf[x];

      int sz = (int)divs.size();

      for (int i = 0; i < sz; i++) {
        divs.push_back(divs[i] * p);
      }

      while (x % p == 0) x /= p;
    }

    int lim = min(v, mx_n), wc = (lim >> 6) + 1;

    vector<uint64_t> sum(words), dp(words);

    for (int d : divs) {
      size_t base = (size_t)id[d] * words;

      for (int w = 0; w < wc; w++) {
        sum[w] ^= c[base + w];
      }
    }

    sum[0] ^= 1;

    uint64_t carry = 0;

    for (int w = 0; w < wc; w++) {
      uint64_t nxt = sum[w] >> 63;
      dp[w] = (sum[w] << 1) | carry;
      carry = nxt;
    }

    if (wc == words && (mx_n & 63) != 63) {
      int bits = (mx_n & 63) + 1;
      dp[wc - 1] &= (uint64_t(1) << bits) - 1;
    }

    for (int d : divs) {
      size_t base = (size_t)id[d] * words;

      for (int w = 0; w < wc; w++) {
        c[base + w] ^= dp[w];
      }
    }

    for (int w = 0; w < wc; w++) {
      pre[w] ^= dp[w];
    }

    for (auto [n, i] : query[v]) {
      ans[i] = (pre[n >> 6] >> (n & 63)) & 1;
    }
  }

  for (int x : ans) cout << x << '\n';
  return 0;
}
