/*!
 * author: manhhomienbienthuy
 * created: 2026-06-25T08:36:33+00:00
 * https://codeforces.com/contest/2184/problem/E
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

    if (n == 2) {
      cout << "1\n";
      continue;
    }

    vector<pair<int, int>> e;
    for (int i = 0; i < n - 1; i++) {
      int d = abs(a[i] - a[i + 1]);
      e.push_back({d, i});
    }
    sort(e.rbegin(), e.rend());

    vector<int> parent(n - 1), size(n - 1, 1);
    vector<bool> active(n - 1, false);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> find = [&](int x) {
      if (parent[x] == x) return x;
      return parent[x] = find(parent[x]);
    };

    auto unite = [&](int a, int b, int64_t& cur) {
      a = find(a);
      b = find(b);
      if (a == b) return;

      int64_t before =
          1ll * size[a] * (size[a] + 1) / 2 + 1ll * size[b] * (size[b] + 1) / 2;

      parent[b] = a;
      size[a] += size[b];

      int64_t after = 1ll * size[a] * (size[a] + 1) / 2;

      cur += (after - before);
    };

    vector<int64_t> ans(n + 1, 0);
    int64_t cur = 0;
    int ptr = 0;

    for (int k = n; k >= 1; k--) {
      while (ptr < n - 1 && e[ptr].first >= k) {
        int i = e[ptr].second;
        active[i] = true;
        cur += 1;

        if (i > 0 && active[i - 1]) {
          unite(i, i - 1, cur);
        }
        if (i + 1 < n - 1 && active[i + 1]) {
          unite(i, i + 1, cur);
        }

        ptr++;
      }

      ans[k] = cur;
    }

    for (int k = 1; k <= n - 1; k++) {
      cout << ans[k] << " ";
    }
    cout << "\n";
  }

  return 0;
}
