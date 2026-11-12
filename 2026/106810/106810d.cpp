/*!
 * author: manhhomienbienthuy
 * created: 2026-11-10T05:18:22+00:00
 * https://codeforces.com/gym/106810/problem/D
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

    vector<int> run;

    for (int i = 0, j; i < n; i = j) {
      for (j = i + 1; j < n && s[j] == s[i]; j++);
      run.push_back(j - i);
    }

    if (run.size() >= 4) {
      cout << "NO\n";
    } else if (run.size() == 3) {
      cout << (run[0] + run[2] <= run[1] ? "YES\n" : "NO\n");
    } else {
      cout << "YES\n";
    }
  }

  return 0;
}
