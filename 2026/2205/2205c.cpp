/*!
 * author: manhhomienbienthuy
 * created: 2026-07-06T01:26:51+00:00
 * https://codeforces.com/contest/2205/problem/C
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
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
      int l;
      cin >> l;
      vector<int> b(l);
      for (auto& x : b) cin >> x;
      reverse(b.begin(), b.end());
      for (auto x : b) {
        if (find(a[i].begin(), a[i].end(), x) == a[i].end()) a[i].push_back(x);
      }
    }

    vector<int> ans;
    while (!a.empty()) {
      auto m = ranges::min(a);
      ans.insert(ans.end(), m.begin(), m.end());
      vector<vector<int>> new_a;
      for (auto x : a) {
        vector<int> tmp;
        for (auto y : x) {
          if (find(ans.begin(), ans.end(), y) == ans.end()) tmp.push_back(y);
        }
        if (!tmp.empty()) new_a.push_back(tmp);
      }
      a = move(new_a);
    }

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}
