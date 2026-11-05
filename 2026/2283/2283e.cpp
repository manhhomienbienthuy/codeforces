/*!
 * author: manhhomienbienthuy
 * created: 2026-11-04T15:55:31+00:00
 * https://codeforces.com/contest/2283/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX = 5000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> bell(MAX + 1), row(1, 1);
  bell[0] = 1;

  for (int i = 1; i <= MAX; i++) {
    vector<int> nxt(i + 1);

    nxt[0] = row.back();

    for (int j = 1; j <= i; j++) {
      nxt[j] = (nxt[j - 1] + row[j - 1]) % MOD;
    }

    bell[i] = nxt[0];
    row.swap(nxt);
  }

  vector<int> ways(MAX + 1);
  ways[0] = 1;

  for (int i = 2; i <= MAX; i++) {
    ways[i] = ways[i - 2];

    if (i >= 3) {
      ways[i] = (ways[i] + ways[i - 3]) % MOD;
    }
  }

  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;

    cin >> n >> s;

    int mix = 0;
    vector<int> cnt(2);
    int64_t ans = 1;

    for (int i = 0, j; i < n; i = j) {
      for (j = i + 1; j < n && s[j] != s[j - 1]; j++);

      int len = j - i;

      if (len == 1) {
        cnt[s[i] - '0']++;
      } else {
        mix += len;
        ans = ans * ways[len] % MOD;
      }
    }

    ans = ans * bell[cnt[0]] % MOD;
    ans = ans * bell[cnt[1]] % MOD;

    cout << n + mix << ' ' << ans << '\n';
  }

  return 0;
}
