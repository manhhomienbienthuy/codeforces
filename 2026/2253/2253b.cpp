/*!
 * author: manhhomienbienthuy
 * created: 2026-08-09T07:50:43+00:00
 * https://codeforces.com/contest/2253/problem/B
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

    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<pair<int, int>> segs;

    for (int i = 0, j; i < n; i = j) {
      for (j = i + 1; j < n && a[j] == a[i]; j++);
      segs.push_back({a[i], j - i});
    }

    int m = (int)segs.size();

    bool one = false, two = false;

    for (int i = 0; i < m - 1; i++) {
      if (segs[i].second > 1 && segs[i + 1].second > 1) {
        one = two = true;
        break;
      } else if (segs[i + 1].second > 1) {
        one = one || !i || segs[i - 1].first != segs[i + 1].first;
      } else if (segs[i].second > 1) {
        one = one || i == m - 2 || segs[i].first != segs[i + 2].first;
      }
    }

    cout << min(n, m + one + two) << '\n';
  }

  return 0;
}
