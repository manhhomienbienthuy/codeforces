/*!
 * author: manhhomienbienthuy
 * created: 2026-11-06T14:56:39+00:00
 * https://codeforces.com/contest/2284/problem/C1
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<bool> sieve(MAX, true);
  sieve[0] = sieve[1] = false;

  for (int i = 2; i * i < MAX; i++) {
    if (sieve[i]) {
      for (int j = i * i; j < MAX; j += i) sieve[j] = false;
    }
  }

  vector<int> nxt(MAX);
  int p = MAX;

  for (int i = MAX - 1; i >= 0; i--) {
    nxt[i] = p;
    if (sieve[i]) p = i;
  }

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cout << nxt[x] << ' ';
    }

    cout << '\n';
  }

  return 0;
}
