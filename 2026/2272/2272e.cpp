/*!
 * author: manhhomienbienthuy
 * created: 2026-10-26T16:02:26+00:00
 * https://codeforces.com/contest/2272/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

struct info {
  int len;
  int last_w;
  vector<int> gaps;
  vector<int64_t> pref;

  info(const string& s) {
    len = (int)s.size();
    last_w = 0;

    vector<int> pos;

    for (int i = 0; i < len; i++) {
      if (s[i] == 'W') {
        pos.push_back(i + 1);
        last_w = i + 1;
      }
    }

    for (int i = 1; i < (int)pos.size(); i++) {
      gaps.push_back(pos[i] - pos[i - 1]);
    }

    sort(gaps.begin(), gaps.end());

    pref.assign(gaps.size() + 1, 0);

    for (int i = 0; i < (int)gaps.size(); i++) {
      pref[i + 1] = pref[i] + gaps[i];
    }
  }

  int64_t uni(int d) const {
    if (last_w == 0) return 0;

    int pos = (int)(lower_bound(gaps.begin(), gaps.end(), d) - gaps.begin());

    int64_t ans = d;
    ans += pref[pos];
    ans += int64_t((int)gaps.size() - pos) * d;

    return ans;
  }
};

vector<int64_t> calc(const string& s, const info& other) {
  vector<int64_t> ans;

  int last_w = 0;

  for (int i = 0; i < (int)s.size(); i++) {
    int p = i + 1;

    if (s[i] == 'W') {
      last_w = p;
      continue;
    }

    if (last_w == 0) {
      ans.push_back(1 + other.uni(p));
    } else {
      int d = p - last_w;

      int64_t cur = other.len + 1;

      if (other.last_w > 0) {
        cur = max(cur, int64_t(other.last_w) + d);
      }

      ans.push_back(cur);
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;

  while (tt--) {
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    info si(s), ti(t);

    vector<int64_t> ans_s = calc(s, ti), ans_t = calc(t, si);

    for (auto x : ans_s) cout << x << ' ';
    cout << '\n';

    for (auto x : ans_t) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}
