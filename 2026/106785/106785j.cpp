/*!
 * author: manhhomienbienthuy
 * created: 2026-11-02T09:45:34+00:00
 * https://codeforces.com/gym/106785/problem/J
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    vector<bool> correct(n);
    int64_t s = 0;

    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      s += min(a[i], b[i]);
      correct[i] = a[i] <= b[i];
    }

    for (int i = 0; i < n; i++) {
      if (!correct[i]) {
        int64_t c = s - b[i] + a[i];
        correct[i] = c <= k;
      }
    }

    cout << accumulate(correct.begin(), correct.end(), 0) << '\n';
  }

  return 0;
}
