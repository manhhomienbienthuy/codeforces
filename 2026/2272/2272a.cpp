/*!
 * author: manhhomienbienthuy
 * created: 2026-10-26T14:38:04+00:00
 * https://codeforces.com/contest/2272/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int calc(const vector<int>& a, int n, int k) {
  vector<bool> visited(n);
  vector<int> f(n);

  int mex = 0;

  for (int i = 0; i < n; i++) {
    visited[a[i]] = true;
    while (visited[mex]) mex++;
    f[i] = mex;
  }

  sort(f.begin(), f.end(), greater<>());
  return f[k - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    int mx = calc(a, n, k);
    int ii = -1, jj = -1;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        swap(a[i], a[j]);

        int cur = calc(a, n, k);

        if (cur > mx) {
          mx = cur;
          ii = i;
          jj = j;
        }

        swap(a[i], a[j]);
      }
    }

    if (ii == -1) {
      cout << -1 << '\n';
    } else {
      cout << ii + 1 << ' ' << jj + 1 << '\n';
    }
  }

  return 0;
}
