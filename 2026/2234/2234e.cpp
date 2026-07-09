/*!
 * author: manhhomienbienthuy
 * created: 2026-07-08T03:43:51+00:00
 * https://codeforces.com/contest/2234/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const int MAXN = 500001;
  vector<int64_t> fact(MAXN), inv_fact(MAXN);
  fact[0] = 1;
  for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;

  auto pw = [&](int64_t b, int64_t e) {
    int64_t r = 1;
    b %= MOD;
    for (; e; e >>= 1) {
      if (e & 1) r = r * b % MOD;
      b = b * b % MOD;
    }
    return r;
  };

  inv_fact[MAXN - 1] = pw(fact[MAXN - 1], MOD - 2);
  for (int i = MAXN - 2; i >= 0; i--)
    inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
  auto calc = [&](int n, int k) -> int64_t {
    if (k < 0 || k > n) return 0;
    return fact[n] % MOD * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
  };

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int64_t ans = 1;

    stack<pair<int, int>> st;
    st.push({0, n - 1});

    bool ok = true;
    while (!st.empty()) {
      auto [l, r] = st.top();
      st.pop();
      if (l > r) continue;
      if (l == r) {
        if (a[l] != 1) {
          ok = false;
          break;
        }
        continue;
      }

      int len = r - l + 1;
      int found = -1;
      for (int k = 0; k < len && found == -1; k++) {
        int idx = (k % 2 == 0) ? l + k / 2 : r - k / 2;
        int64_t left = idx - l + 1, right = r - idx + 1;
        if (a[idx] == left * right) found = idx;
      }
      if (found == -1) {
        ok = false;
        break;
      }

      int i = found;
      ans = ans % MOD * calc(r - l, i - l) % MOD;
      st.push({l, i - 1});
      st.push({i + 1, r});
    }

    if (!ok)
      cout << 0 << "\n";
    else
      cout << ans % MOD << "\n";
  }
  return 0;
}

/*
Problem: Count permutations p where a[i] = number of subarrays with minimum
p[i].

=== a[i] formula ===
p[i] is minimum of p[l..r] iff p[i] < all elements to its left up to first
smaller, and < all to its right up to first smaller. a[i] = (left_extent) *
(right_extent) = number of subarrays with min p[i].

=== Recursive structure (from editorial) ===
On interval [l, r] with some set of values to place:
1. Find index i in [l,r] where a[i] = (i-l+1)*(r-i+1).
   => p[i] must be the minimum on [l,r].
2. If none found: 0 ways.
3. Answer = kL * kR * C(r-l, i-l)
   - C(r-l, i-l) ways to split remaining r-l values between left and right
   - kL = answer for subproblem [l, i-1]
   - kR = answer for subproblem [i+1, r]

=== Search order ===
Search from boundaries inward: l, r, l+1, r-1, ...
This gives O(n log n) time (editorial Claim).

=== Implementation ===
- Iterative with explicit stack to avoid recursion depth O(n)
- Precompute factorials for C(n, k) mod 1e9+7
- Overflow: (i-l+1)*(r-i+1) <= (n/2)^2 ~ 6e10 for n=5e5, fits int64_t

=== Verification ===
Ex1 [1,4,1]: found i=1, C(2,1)=2, recurse [0,0],[2,2] both a=1 => 2 ✓
Ex2 [1,2,3,4]: chain i=3->2->1->0, all C=1 => 1 ✓
Ex3 [1,6,1,2]: i=1 first, C(3,1)=3; recurse [0,0],[2,3]; [2,3] i=3, C(1,1)=1 =>
3 ✓ Ex4 [3,3,3]: i=0 found, recurse [1,2]; a[1]=3,a[2]=3 but (1)*(2)=2 != 3 -> 0
✓
*/
