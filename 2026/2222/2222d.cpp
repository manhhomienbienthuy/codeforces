/*!
 * author: manhhomienbienthuy
 * created: 2026-07-23T09:24:14+00:00
 * https://codeforces.com/contest/2222/problem/D
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
    for (auto& x : a) cin >> x;

    vector<int64_t> pref(n + 1, 0);
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
         [&](int x, int y) { return pref[x] > pref[y]; });

    vector<int> ans(n);

    for (int i = 0; i < n; i++) ans[idx[i]] = i + 1;

    for (int x : ans) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}
