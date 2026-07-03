/*!
 * author: manhhomienbienthuy
 * created: 2026-07-03T01:54:14+00:00
 * https://codeforces.com/contest/2216/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

bool check(int64_t m, int64_t b, int64_t p) {
  int64_t base = 1;
  for (int i = 0; i < p; i++) base *= b;

  while (m > 0) {
    if (m % base >= b) return false;
    m /= base;
  }

  return true;
}

int64_t find_b(int64_t s, int p) {
  if (p == 2) return s > 2 ? s - 1 : -1;

  int64_t lo = 2, hi = (int64_t)pow(s, 1.0 / (p - 1)) + 3;
  while (lo <= hi) {
    int64_t mid = (lo + hi) / 2;
    int64_t val = 0, pw = 1;
    bool ok = true;
    for (int i = 0; i < p; i++) {
      val += pw;
      if (val > s) {
        ok = false;
        break;
      }
      pw *= mid;
    }

    if (!ok)
      hi = mid - 1;
    else if (val < s)
      lo = mid + 1;
    else
      return mid;
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;

    vector<int64_t> d;
    for (int64_t i = 1; i * i < n; i++) {
      if (n % i == 0) {
        d.push_back(i);
        if (i * i != n) d.push_back(n / i);
      }
    }

    int64_t ans = 0;
    for (auto s : d) {
      if (s < 3) continue;
      int64_t m = n / s;
      for (int p = 2; p <= 40; p++) {
        if ((1ll << p) > s + 1) break;
        int64_t b = find_b(s, p);
        ans += (b >= 2) && check(m, b, p);
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
