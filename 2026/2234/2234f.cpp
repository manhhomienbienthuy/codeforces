/*!
 * author: manhhomienbienthuy
 * created: 2026-06-23T07:31:00+00:00
 * https://codeforces.com/contest/2234/problem/F
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
    vector<int> h(n);
    for (auto& x : h) cin >> x;
    int p = 0;
    for (int i = 1; i < n; i++) {
      if (h[i] > h[p]) p = i;
    }
    vector<int> a = h;
    rotate(a.begin(), a.begin() + p, a.end());

    vector<int> nx_f(n, 0), nx_b(n, 0);
    stack<int> s_f, s_b;
    for (int i = n - 1; i > 0; i--) {
      while (!s_f.empty() && a[s_f.top()] <= a[i]) {
        s_f.pop();
      }
      nx_f[i] = s_f.empty() ? n : s_f.top();
      s_f.push(i);

      while (!s_b.empty() && a[s_b.top()] <= a[n - i]) {
        s_b.pop();
      }
      nx_b[n - i] = s_b.empty() ? 0 : s_b.top();
      s_b.push(n - i);
    }

    vector<int64_t> fdp(n, 0), bdp(n, 0);
    for (int i = n - 1; i > 0; i--) {
      fdp[i - 1] = 1ll * a[i] * (nx_f[i] - i) + fdp[nx_f[i] - 1];
      bdp[n - i] = 1ll * a[n - i] * (n - i - nx_b[n - i]) + bdp[nx_b[n - i]];
    }

    vector<int64_t> ans(n);
    for (int i = 0; i < n; i++) {
      int v = (p + i + 1) % n;
      ans[v] = fdp[i] + bdp[i];
    }

    for (auto x : ans) cout << x << " ";
    cout << "\n";
  }

  return 0;
}
