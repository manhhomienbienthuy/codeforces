/*!
 * author: manhhomienbienthuy
 * created: 2026-11-04T00:48:26+00:00
 * https://codeforces.com/gym/106785/problem/G
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    int mxx = INT_MIN, mnx = INT_MAX, mxy = INT_MIN, mny = INT_MAX;

    for (int i = 0; i < n; i++) {
      cin >> a[i].first >> a[i].second;
      mnx = min(mnx, a[i].first);
      mxx = max(mxx, a[i].first);
      mny = min(mny, a[i].second);
      mxy = max(mxy, a[i].second);
    }

    bool it1 = find(a.begin(), a.end(), pair<int, int>{mnx, mny}) != a.end(),
         it2 = find(a.begin(), a.end(), pair<int, int>{mnx, mxy}) != a.end(),
         it3 = find(a.begin(), a.end(), pair<int, int>{mxx, mny}) != a.end(),
         it4 = find(a.begin(), a.end(), pair<int, int>{mxx, mxy}) != a.end();

    bool ok = it1 && it2 && it3 && it4;

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
