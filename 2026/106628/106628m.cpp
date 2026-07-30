/*!
 * author: manhhomienbienthuy
 * created: 2026-07-30T03:10:37+00:00
 * https://codeforces.com/gym/106628/problem/M
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int C, Q;
    cin >> C >> Q;

    list<int> pool;

    unordered_map<int, list<int>::iterator> pos;
    unordered_set<int> dirty;

    auto touch = [&](int x) {
      auto it = pos.find(x);

      if (it != pos.end()) {
        pool.erase(it->second);
      }

      pool.push_back(x);
      pos[x] = prev(pool.end());

      if ((int)pool.size() > C) {
        int y = pool.front();
        pool.pop_front();

        pos.erase(y);
        dirty.erase(y);
      }
    };

    while (Q--) {
      int o;
      cin >> o;

      if (o == 1) {
        int x;
        cin >> x;

        touch(x);
      } else if (o == 2) {
        int x;
        cin >> x;

        dirty.insert(x);
        touch(x);
      } else if (o == 3) {
        cout << dirty.size() << '\n';
        dirty.clear();
      } else {
        int x;
        cin >> x;

        cout << (pos.count(x) > 0) << ' ' << (dirty.count(x) > 0) << '\n';
      }
    }
  }

  return 0;
}
