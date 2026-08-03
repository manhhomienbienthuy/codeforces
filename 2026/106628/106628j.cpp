/*!
 * author: manhhomienbienthuy
 * created: 2026-07-30T07:41:30+00:00
 * https://codeforces.com/gym/106628/problem/J
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> z_func(const string& s) {
  int n = (int)s.size();

  vector<int> z(n);

  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);

    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;

    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }

  return z;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    int n = (int)s.size();

    auto z = z_func(s);

    string rs = s;
    reverse(rs.begin(), rs.end());

    auto zr = z_func(rs);

    int64_t ans = 0;

    for (int k = 1; k < n; k++) {
      int lcs = min(zr[n - k], k);

      int lo = max({1, 2 * k - n, k - lcs});
      int hi = min({k - 1, n - k, z[k]});

      if (lo <= hi) {
        ans += hi - lo + 1;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
