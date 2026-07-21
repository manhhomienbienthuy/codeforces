/*!
 * author: manhhomienbienthuy
 * created: 2026-07-21T01:28:20+00:00
 * https://codeforces.com/gym/704573/problem/C2
 */

#include <bits/stdc++.h>
using namespace std;

const int M = 2e5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, c;
  cin >> n >> c;

  vector<int> freq(M + 1, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    freq[x]++;
  }

  vector<int> pref(M + 1, 0);
  for (int i = 1; i <= M; i++) {
    pref[i] = pref[i - 1] + freq[i];
  }

  int64_t ans = 0;

  for (int x = 1; x <= M; x++) {
    if (!pref[x]) continue;

    int64_t cur = 0;

    for (int k = 1; k * x <= M; k++) {
      int l = k * x;
      int r = min(M, (k + 1) * x - 1);

      if (x > c) {
        int cnt = pref[r] - pref[l - 1];
        cur += 1LL * cnt * k * (x - c) + 1LL * freq[l] * c;
      } else if (l > 1LL * (k - 1) * c) {
        cur += 1LL * freq[l] * (0LL + l - 1LL * (k - 1) * c);
      }
    }

    ans = max(ans, cur);
  }

  cout << ans << '\n';
  return 0;
}
