/*!
 * author: manhhomienbienthuy
 * created: 2026-08-19T07:45:52+00:00
 * https://codeforces.com/contest/2257/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

struct seg {
  int64_t need;
  int64_t gain;
  int nxt;
  int id;
  int h;
};

struct node {
  int64_t need;
  int id;

  bool operator<(const node& other) const { return need > other.need; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    int64_t x;
    cin >> n >> x;

    vector<vector<int>> a(n), b(n);

    vector<vector<seg>> segs(n);
    vector<int> m(n);

    for (int i = 0; i < n; i++) {
      cin >> m[i];

      a[i].resize(m[i]);
      b[i].resize(m[i]);

      for (int& x : a[i]) cin >> x;
      for (int& x : b[i]) cin >> x;

      int pos = 0;

      while (pos < m[i]) {
        int l = pos;

        int64_t sum = 0;

        while (pos < m[i]) {
          sum += (int64_t)b[i][pos] - a[i][pos];
          pos++;

          if (sum >= 0) break;
        }

        if (sum < 0) break;

        int64_t need = 0;
        int64_t pref = 0;

        for (int j = l; j < pos; j++) {
          need = max(need, (int64_t)a[i][j] - pref);
          pref += (int64_t)b[i][j] - a[i][j];
        }

        segs[i].push_back({need, sum, (int)segs[i].size() + 1, i, pos});
      }
    }

    priority_queue<node> pq;

    for (int i = 0; i < n; i++) {
      if (!segs[i].empty()) {
        pq.push({segs[i][0].need, i});
      }
    }

    vector<int> h(n, 0);
    vector<int> ptr(n, 0);

    int64_t mx_cap = x;

    while (!pq.empty()) {
      auto [need, id] = pq.top();

      if (need > mx_cap) break;

      pq.pop();

      int p = ptr[id];
      auto& s = segs[id][p];

      mx_cap += s.gain;
      h[id] = s.h;

      ptr[id]++;

      if (ptr[id] < (int)segs[id].size()) {
        pq.push({segs[id][ptr[id]].need, id});
      }
    }

    int best_h = -1;
    int best_id = -1;

    for (int i = 0; i < n; i++) {
      int cur_h = h[i];
      int64_t cap = mx_cap;

      for (int j = cur_h; j < m[i]; j++) {
        if (cap < a[i][j]) break;

        cap += (int64_t)b[i][j] - a[i][j];
        cur_h++;
      }

      if (cur_h > best_h) {
        best_h = cur_h;
        best_id = i + 1;
      }
    }

    cout << best_h << ' ' << best_id << '\n';
  }

  return 0;
}
