/*!
 * author: manhhomienbienthuy
 * created: 2026-11-22T10:39:50+00:00
 * https://codeforces.com/contest/2289/problem/C
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

    vector<int> p(n);
    for (int& x : p) cin >> x;

    vector<int> prev(n, -1);
    stack<int> st1;

    for (int i = 0; i < n; i++) {
      while (!st1.empty() && p[st1.top()] > p[i]) st1.pop();

      if (!st1.empty()) prev[i] = st1.top();
      st1.push(i);
    }

    vector<int> nxt(n, n);
    stack<int> st2;

    for (int i = n - 1; i >= 0; i--) {
      while (!st2.empty() && p[st2.top()] > p[i]) st2.pop();

      if (!st2.empty()) nxt[i] = st2.top();
      st2.push(i);
    }

    int64_t ans = 0;

    for (int i = 0; i < n; i++) {
      int l = i - prev[i], r = nxt[i] - i;

      if (l == 1 || r == 1)
        ans += l + r - 1;
      else
        ans += 2;
    }

    cout << ans << '\n';
  }

  return 0;
}
