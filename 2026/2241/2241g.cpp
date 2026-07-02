/*!
 * author: manhhomienbienthuy
 * created: 2026-07-02T04:16:53+00:00
 * https://codeforces.com/contest/2241/problem/G
 */

#include <bits/stdc++.h>
using namespace std;

void print(__int128_t x) {
  string s;

  if (x == 0)
    s = "0";
  else {
    while (x) {
      s.push_back(char('0' + x % 10));
      x /= 10;
    }
    reverse(s.begin(), s.end());
  }

  cout << s << '\n';
}

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

    vector<int> pos(n, n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && a[i] % a[st.top()]) {
        int j = st.top();
        st.pop();
        pos[j] = i;
      }
      st.push(i);
    }

    __int128_t ans = 0;
    for (int i = 0; i < n; i++) {
      if (pos[i] == n) continue;

      int x = a[pos[i]];
      int y = x % a[i];
      ans += 1ll * (n - pos[i]) * min(y, a[i] - y);
    }

    print(ans);
  }
  return 0;
}
