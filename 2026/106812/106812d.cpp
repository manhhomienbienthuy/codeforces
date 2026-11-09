/*!
 * author: manhhomienbienthuy
 * created: 2026-11-09T02:53:19+00:00
 * https://codeforces.com/gym/106812/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<bool> sieve(n + 1, true);
  sieve[0] = sieve[1] = false;

  for (int i = 2; i * i <= n; i++) {
    if (sieve[i]) {
      for (int j = i * i; j <= n; j += i) sieve[j] = false;
    }
  }

  vector<int> primes;
  for (int i = 2; i < n; i++) {
    if (sieve[i]) primes.push_back(i);
  }

  int m = (int)primes.size();

  vector<int64_t> ans;

  for (int i = 0; i < m; i++) {
    for (int j = i; j < m; j++) {
      int64_t x = 1LL * primes[i] * primes[j];

      if (x > n) break;

      ans.push_back(x);
    }
  }

  sort(ans.begin(), ans.end());

  for (int64_t x : ans) cout << x << ' ';
  cout << '\n';

  return 0;
}
