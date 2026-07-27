/*!
 * author: manhhomienbienthuy
 * created: 2026-07-24T08:44:59+00:00
 * https://codeforces.com/contest/2209/problem/D
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    vector<pair<int, char>> v(3);
    for (auto& x : v) cin >> x.first;

    v[0].second = 'R';
    v[1].second = 'G';
    v[2].second = 'B';
    sort(v.begin(), v.end(),
         [](const auto& a, const auto& b) { return a.first > b.first; });

    int r = v[0].first;
    int g = v[1].first;
    int b = v[2].first;

    char cr = v[0].second;
    char cg = v[1].second;
    char cb = v[2].second;

    string ans;

    if (r > g + b + 1) {
      while (g--) {
        ans.push_back(cr);
        ans.push_back(cg);
      }
      while (b--) {
        ans.push_back(cr);
        ans.push_back(cb);
      }
      ans.push_back(cr);
    } else {
      int x = g - b;
      int rem_r = r - x;
      int p = rem_r / 2;

      if (rem_r & 1) {
        ans.push_back(cr);
        rem_r--;
      }

      for (int i = 0; i < x; i++) {
        ans.push_back(cg);
        ans.push_back(cr);
      }

      for (int i = 0; i < p; i++) {
        ans.push_back(cb);
        ans.push_back(cr);
        ans.push_back(cg);
        ans.push_back(cr);
      }

      for (int i = p; i < b; i++) {
        ans.push_back(cg);
        ans.push_back(cb);
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
