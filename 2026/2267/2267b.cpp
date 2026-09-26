/*!
 * author: manhhomienbienthuy
 * created: 2026-09-26T07:15:26+00:00
 * https://codeforces.com/contest/2267/problem/B
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

    vector<int> freq(101);

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      freq[x]++;
    }

    while (n) {
      for (int i = 100; i > 0; i--) {
        if (!freq[i]) continue;

        cout << i << ' ';
        n--;
        freq[i]--;
      }
    }

    cout << '\n';
  }

  return 0;
}
