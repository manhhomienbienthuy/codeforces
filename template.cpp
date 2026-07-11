/*!
 * author: manhhomienbienthuy
 * template C++ for Codeforces
 */

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// power of 2
int64_t power(int64_t p) {
  if (p < 30) return (1 << p) % MOD;
  int64_t r = power(p / 2);
  return (r * r * (1 << (p & 1))) % MOD;
}

// power of a
int64_t power(int64_t a, int64_t p) {
  int64_t r = 1;
  while (p > 0) {
    if (p & 1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    p >>= 1;
  }
  return r;
}

// get MSB
int64_t setBitNumber(int64_t n) {
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n |= n >> 32;
  n = (n >> 1) + 1;
  return n;
}

const int MAX = 510000;
int64_t fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void fact_init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// longest common subsequence
int lcs(vector<int>& s1, vector<int>& s2) {
  int n = s1.size();
  int m = s2.size();

  // Initializing a matrix of size (m+1)*(n+1)
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  // Building dp[m+1][n+1] in bottom-up fashion
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  // dp[m][n] contains length of LCS for s1[0..m-1]
  // and s2[0..n-1]
  return dp[n][m];
}

// longest increasing subsequence
int find_lis(const vector<int>& a) {
  vector<int> dp;
  for (int i : a) {
    int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
    if (pos == dp.size()) {
      // we can have a new, longer increasing subsequence!
      dp.push_back(i);
    } else {
      // oh ok, at least we can make the ending element smaller
      dp[pos] = i;
    }
  }
  return dp.size();
}

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

struct fenwick {
  int n;
  vector<int64_t> bit;

  fenwick(int n_) : n(n_), bit(n + 1, 0) {}

  void add(int p, int64_t v) {
    for (; p <= n; p += p & -p) {
      bit[p] += v;
    }
  }

  int64_t sum(int p) const {
    int64_t res = 0;
    for (; p > 0; p -= p & -p) {
      res += bit[p];
    }
    return res;
  }

  int64_t sum(int l, int r) const { return sum(r) - sum(l - 1); }
};

struct FastHash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    // coordinate compression
    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = (int)vals.size();

    auto gid = [&](int x) {
      return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
    };

    int64_t ans = 1e18;
    int i = 0;
    while (i < n) {
      int j = i;
      while (j < n && a[i] == a[j]) j++;
      ans = min(ans, 1ll * a[i] * (n - j + i));
      i = j;
    }

    cout << ans << '\n';
  }

  return 0;
}
