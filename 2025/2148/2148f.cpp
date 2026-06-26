/*!
 * author: manhhomienbienthuy
 * created: 2026-06-26T06:30:26+00:00
 * https://codeforces.com/contest/2148/problem/F
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
      int k;
      cin >> k;
      a[i].resize(k);
      for (auto& x : a[i]) {
        cin >> x;
      }
    }

    vector<int> ans;

    while (!a.empty()) {
      auto first = *min_element(a.begin(), a.end());
      auto l = first.size();
      ans.insert(ans.end(), first.begin(), first.end());

      vector<vector<int>> next;
      for (auto x : a) {
        if (x.size() > l) {
          vector<int> tmp(x.begin() + l, x.end());
          next.push_back(tmp);
        }
      }

      a = move(next);
    }

    for (auto x : ans) cout << x << " ";
    cout << "\n";
  }

  return 0;
}
