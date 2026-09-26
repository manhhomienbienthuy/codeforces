/*!
 * author: manhhomienbienthuy
 * created: 2026-09-26T13:50:19+00:00
 * https://codeforces.com/contest/2267/problem/F1
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
    for (int& x : a) cin >> x;

    vector<int64_t> query(q);
    int64_t mx_q = 0;

    for (int i = 0; i < q; i++) {
      cin >> query[i];
      mx_q = max(mx_q, query[i]);
    }

    vector<int> diff;

    auto get_diff = [&](const vector<int>& v) {
      auto [mn_it, mx_it] = minmax_element(v.begin(), v.end());
      return *mx_it - *mn_it;
    };

    int stop = -1;

    for (int step = 1; step <= 30; step++) {
      diff.push_back(get_diff(a));

      if (diff.back() == 0) {
        stop = step;
        break;
      }

      vector<int> vals;
      vals.reserve(1LL * n * (n - 1) / 2);

      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          vals.push_back(a[i] ^ a[j]);
        }
      }

      nth_element(vals.begin(), vals.begin() + n, vals.end());

      vals.resize(n);
      a = move(vals);
    }

    if (stop == -1) stop = (int)diff.size() - 1;

    for (auto x : query) cout << (x >= stop ? 0 : diff[(int)x]) << '\n';
  }

  return 0;
}
