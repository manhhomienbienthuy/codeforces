/*!
 * author: manhhomienbienthuy
 * created: 2026-08-09T07:47:31+00:00
 * https://codeforces.com/contest/2253/problem/A
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
    n++;

    bool ok = true;

    for (int i = 2; ok && i < sqrt(n) + 1; i++) ok = n % i;

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
