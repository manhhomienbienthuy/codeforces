/*!
 * author: manhhomienbienthuy
 * created: 2026-10-07T15:02:34+00:00
 * https://codeforces.com/contest/2275/problem/B
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

    vector<bool> print(n, false);
    vector<int> scan;

    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        scan.push_back(i);
      } else if (s[i] == '2') {
        if (!scan.empty()) {
          print[scan.back()] = true;
          scan.pop_back();
        } else
          print[i] = true;
      } else
        print[i] = true;
    }

    cout << n - accumulate(print.begin(), print.end(), 0) << '\n';
    for (int i = 0; i < n; i++) {
      if (!print[i]) cout << i + 1 << ' ';
    }
    cout << '\n';
  }

  return 0;
}
