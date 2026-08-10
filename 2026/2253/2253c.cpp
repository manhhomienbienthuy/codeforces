/*!
 * author: manhhomienbienthuy
 * created: 2026-08-09T11:31:57+00:00
 * https://codeforces.com/contest/2253/problem/C
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<int> a(x), b(y);

    for (int& v : a) cin >> v;
    for (int& v : b) cin >> v;

    vector<int> only_a, only_b, common;

    int64_t total = 0;

    int i = 0;
    int j = 0;

    while (i < x || j < y) {
      if (j == y || (i < x && a[i] < b[j])) {
        only_a.push_back(a[i]);
        total += a[i];
        i++;
      } else if (i == x || b[j] < a[i]) {
        only_b.push_back(b[j]);
        total += b[j];
        j++;
      } else {
        common.push_back(a[i]);
        total += a[i];
        i++;
        j++;
      }
    }

    int a_sz = (int)only_a.size();
    int b_sz = (int)only_b.size();
    int c_sz = (int)common.size();

    vector<int64_t> pref_a(a_sz + 1, 0), pref_b(b_sz + 1, 0);
    for (int i = 0; i < a_sz; i++) pref_a[i + 1] = pref_a[i] + only_a[i];
    for (int i = 0; i < b_sz; i++) pref_b[i + 1] = pref_b[i] + only_b[i];

    auto calc = [&](int p, int q) -> int64_t {
      int keep_a = min(a_sz, p), keep_b = min(b_sz, q);

      int remove_a = a_sz - keep_a, remove_b = b_sz - keep_b;

      int64_t loss = pref_a[remove_a] + pref_b[remove_b];

      int over = keep_a + keep_b + c_sz - (p + q);

      if (over > 0) {
        int ia = remove_a;
        int ib = remove_b;
        int ic = 0;

        while (over--) {
          int va = (ia < a_sz ? only_a[ia] : INT_MAX);
          int vb = (ib < b_sz ? only_b[ib] : INT_MAX);
          int vc = (ic < c_sz ? common[ic] : INT_MAX);

          if (va <= vb && va <= vc) {
            loss += va;
            ia++;
          } else if (vb <= va && vb <= vc) {
            loss += vb;
            ib++;
          } else {
            loss += vc;
            ic++;
          }
        }
      }

      return total - loss;
    };

    int64_t ans = max(calc(n - 1, m), calc(n, m - 1));

    cout << ans << '\n';
  }

  return 0;
}
