/*!
 * author: manhhomienbienthuy
 * created: 2026-07-01T05:40:15+00:00
 * https://codeforces.com/contest/2241/problem/F
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
    string s;
    cin >> n >> s;

    int start, stop;
    for (start = 0; start < n && s[start] == '0'; start++);
    for (stop = n - 1; stop >= 0 && s[stop] == '1'; stop--);

    if (start >= stop) {
      cout << "Bob\n";
      continue;
    } else if (!((stop - start) & 1)) {
      cout << "Alice\n";
      continue;
    }

    bool ok = false;
    int c = 1;
    for (int i = start + 1; i <= stop; i++) {
      if (s[i] != s[i - 1]) {
        if (c & 1) {
          ok = true;
          break;
        }
        c = 1;
      } else
        c++;
    }
    if (c & 1) ok = true;

    cout << (ok ? "Alice\n" : "Bob\n");
  }

  return 0;
}
