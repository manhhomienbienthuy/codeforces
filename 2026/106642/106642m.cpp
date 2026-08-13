/*!
 * author: manhhomienbienthuy
 * created: 2026-08-13T06:59:57+00:00
 * https://codeforces.com/gym/106642/problem/M
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;

  while (tt--) {
    int n;
    cin >> n;

    /*
    ai - aj = bi - bj => ai - bi = aj - bj
    ai - aj = bj - bi => ai + bi = aj + bj
    */

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first;
    for (int i = 0; i < n; i++) cin >> p[i].second;

    vector<int> d(n), s(n);
    for (int i = 0; i < n; i++) {
      d[i] = p[i].first - p[i].second;
      s[i] = p[i].first + p[i].second;
    }

    auto calc = [&](auto& v) {
      sort(v.begin(), v.end());

      int64_t res = 0;

      for (int i = 0, j; i < n; i = j) {
        for (j = i + 1; j < n && v[j] == v[i]; j++);

        int len = j - i;
        res += 1LL * len * (len - 1) / 2;
      }

      return res;
    };

    cout << calc(d) + calc(s) - calc(p) << '\n';
  }

  return 0;
}
