/*!
 * author: manhhomienbienthuy
 * created: 2026-07-20T00:50:01+00:00
 * https://codeforces.com/contest/2247/problem/D1
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    vector<int> b = a;
    sort(b.begin(), b.end());

    unordered_map<int, vector<int>> pos;
    pos.reserve(n * 2);
    for (int i = n - 1; i >= 0; i--) {
      pos[b[i]].push_back(i);
    }

    int x = 0;
    for (int i = 0; i < n; i++) {
      int p = pos[a[i]].back();
      pos[a[i]].pop_back();
      x = max(x, i ^ p);
    }

    if (!x)
      cout << 0 << '\n';
    else {
      x |= x >> 1;
      x |= x >> 2;
      x |= x >> 4;
      x |= x >> 8;
      x |= x >> 16;
      x = (x >> 1) + 1;
      cout << x << '\n';
    }
  }

  return 0;
}
