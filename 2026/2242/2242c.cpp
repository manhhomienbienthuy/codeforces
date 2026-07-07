/*!
 * author: manhhomienbienthuy
 * created: 2026-07-06T14:52:02+00:00
 * https://codeforces.com/contest/2242/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    vector<int> len;
    int i = 0;
    while (i < n) {
      int j;
      for (j = i; j < n && a[j] == a[i]; j++);
      len.push_back(j - i);
      i = j;
    }
    sort(len.begin(), len.end());

    int m = (int)len.size();
    int64_t ans = 0, c = 0;
    int cnt = 0;

    int idx = m - 1;
    while (idx >= 0) {
      int u = len[idx];
      while (idx >= 0 && len[idx] == u) {
        c += len[idx];
        cnt++;
        idx--;
      }

      int64_t r = 0ll + k - c;
      if (r % cnt == 0) {
        int64_t v = r / cnt;
        if (v >= 1 - u) ans++;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
