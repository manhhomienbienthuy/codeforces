/*!
 * author: manhhomienbienthuy
 * created: 2026-10-05T09:01:22+00:00
 * https://codeforces.com/contest/2267/problem/E
 */

#include <bits/stdc++.h>
using namespace std;

struct seg_tree {
  int n;
  vector<int> one;
  vector<bool> lazy;

  seg_tree(const vector<int>& a) : n((int)a.size()), one(4 * n), lazy(4 * n) {
    build(1, 0, n - 1, a);
  }

  void build(int v, int l, int r, const vector<int>& a) {
    if (l == r) {
      one[v] = a[l];
      return;
    }

    int m = (l + r) >> 1;

    build(v << 1, l, m, a);
    build(v << 1 | 1, m + 1, r, a);

    one[v] = one[v << 1] + one[v << 1 | 1];
  }

  void apply(int v, int l, int r) {
    one[v] = r - l + 1 - one[v];
    lazy[v] = !lazy[v];
  }

  void push(int v, int l, int r) {
    if (!lazy[v] || l == r) return;

    int m = (l + r) >> 1;

    apply(v << 1, l, m);
    apply(v << 1 | 1, m + 1, r);

    lazy[v] = false;
  }

  void flip(int v, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return;

    if (ql <= l && r <= qr) {
      apply(v, l, r);
      return;
    }

    push(v, l, r);

    int m = (l + r) >> 1;

    flip(v << 1, l, m, ql, qr);
    flip(v << 1 | 1, m + 1, r, ql, qr);

    one[v] = one[v << 1] + one[v << 1 | 1];
  }

  void flip(int l, int r) {
    if (l <= r) {
      flip(1, 0, n - 1, l, r);
    }
  }

  int count_one() const { return one[1]; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> b(max(0, n - 1));
    vector<int> pref(n);

    int64_t sum = 0;

    for (int j = 0; j + 1 < n; j++) {
      b[j] = s[j] != s[j + 1];
      pref[j + 1] = pref[j] ^ b[j];

      if (b[j]) {
        sum += 1LL * (j + 1) * (n - j - 1);
      }
    }

    seg_tree st(pref);

    auto print_ans = [&]() {
      int64_t one = st.count_one();
      int64_t odd = one * (n - one);
      int64_t ans = (sum + odd) >> 1;

      cout << ans << ' ';
    };

    print_ans();

    while (q--) {
      int i;
      cin >> i;
      i--;

      if (i > 0) {
        int j = i - 1;
        int64_t w = 1LL * (j + 1) * (n - j - 1);

        sum += b[j] ? -w : w;
        b[j] ^= 1;

        st.flip(j + 1, n - 1);
      }

      if (i + 1 < n) {
        int j = i;
        int64_t w = 1LL * (j + 1) * (n - j - 1);

        sum += b[j] ? -w : w;
        b[j] ^= 1;

        st.flip(j + 1, n - 1);
      }

      s[i] ^= 1;

      print_ans();
    }

    cout << '\n';
  }

  return 0;
}
