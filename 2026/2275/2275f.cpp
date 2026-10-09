/*!
 * author: manhhomienbienthuy
 * created: 2026-10-08T05:41:17+00:00
 * https://codeforces.com/contest/2275/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 1;
int spf[MAXN];
int64_t rnd[MAXN];

void init() {
  for (int i = 2; i < MAXN; i++) {
    if (!spf[i]) {
      spf[i] = i;
      for (int64_t j = 1LL * i * i; j < MAXN; j += i) {
        if (!spf[j]) spf[j] = i;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    map<vector<int>, int> id_mp;
    int nxt_id = 0;

    auto get_id = [&](const vector<int>& v) -> int {
      auto it = id_mp.find(v);

      if (it != id_mp.end()) {
        return it->second;
      }

      int id = nxt_id++;
      id_mp[v] = id;
      return id;
    };

    vector<int> a_id(n);

    unordered_map<int, int64_t> cnt_a;

    for (int i = 0; i < n; i++) {
      int x = a[i];

      vector<int> kernel;

      while (x > 1) {
        int p = spf[x];
        int c = 0;

        while (x % p == 0) {
          x /= p;
          c++;
        }

        if (c & 1) {
          kernel.push_back(p);
        }
      }

      int id = get_id(kernel);
      a_id[i] = id;
      cnt_a[id]++;
    }

    vector<int> odd;
    int64_t ans = 0;

    for (int i = 0; i < n; i++) {
      int x = a[i];

      while (x > 1) {
        int p = spf[x];
        int c = 0;

        while (x % p == 0) {
          x /= p;
          c++;
        }

        if (c & 1) {
          auto it = lower_bound(odd.begin(), odd.end(), p);

          if (it != odd.end() && *it == p) {
            odd.erase(it);
          } else {
            odd.insert(it, p);
          }
        }
      }

      int pref_id = get_id(odd);
      ans += cnt_a[pref_id];
    }

    cout << ans << '\n';
  }

  return 0;
}
