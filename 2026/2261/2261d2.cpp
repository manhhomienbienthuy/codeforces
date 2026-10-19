/*!
 * author: manhhomienbienthuy
 * created: 2026-10-17T15:25:42+00:00
 * https://codeforces.com/contest/2261/problem/D2
 */

#include <bits/stdc++.h>
using namespace std;

using u64 = uint64_t;

struct color_t {
  u64 x;
  u64 y;

  bool operator==(const color_t& other) const {
    return x == other.x && y == other.y;
  }
};

struct color_hash {
  size_t operator()(const color_t& value) const {
    return static_cast<size_t>(value.x ^ std::rotl(value.y, 23));
  }
};

static u64 splitmix64(u64 x) {
  x += 0x9e3779b97f4a7c15ULL;
  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
  x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
  return x ^ (x >> 31);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<color_t> event(n + 1, {0, 0});

    for (int id = 0; id < m; ++id) {
      int l, r;
      cin >> l >> r;
      --l;

      u64 tag1 = splitmix64(static_cast<u64>(id) + 0x123456789abcdef0ULL);
      u64 tag2 = splitmix64(static_cast<u64>(id) + 0xfedcba9876543210ULL);

      event[l].x ^= tag1;
      event[l].y ^= tag2;

      event[r].x ^= tag1;
      event[r].y ^= tag2;
    }

    // Calculate the original report-vector color of each position.
    vector<color_t> color(n);

    color_t current{0, 0};

    for (int i = 0; i < n; ++i) {
      current.x ^= event[i].x;
      current.y ^= event[i].y;
      color[i] = current;
    }

    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }

    // Duplicate the sequence to handle circular starting positions.
    vector<color_t> doubled(2 * n);

    for (int i = 0; i < 2 * n; ++i) {
      doubled[i] = color[i % n];
    }

    /*
     * nxt[i] is the first index after the longest rainbow segment
     * beginning at i. We only need starting positions below n, but
     * successors may lie as far as 2n.
     */
    vector<int> nxt(2 * n + 1, 2 * n);

    unordered_map<color_t, int, color_hash> frequency;
    frequency.reserve(4 * n + 1);
    frequency.max_load_factor(0.7f);

    int right = 0;

    for (int left = 0; left < 2 * n; ++left) {
      right = max(right, left);

      while (right < 2 * n) {
        auto it = frequency.find(doubled[right]);

        if (it != frequency.end() && it->second > 0) {
          break;
        }

        ++frequency[doubled[right]];
        ++right;
      }

      nxt[left] = right;

      auto it = frequency.find(doubled[left]);

      if (it != frequency.end()) {
        --it->second;

        if (it->second == 0) {
          frequency.erase(it);
        }
      }
    }

    nxt[2 * n] = 2 * n;

    int log = 1;

    while ((1 << log) <= 2 * n) {
      ++log;
    }

    vector<vector<int>> jump(log, vector<int>(2 * n + 1));

    for (int i = 0; i <= 2 * n; ++i) {
      jump[0][i] = nxt[i];
    }

    for (int level = 1; level < log; ++level) {
      for (int i = 0; i <= 2 * n; ++i) {
        jump[level][i] = jump[level - 1][jump[level - 1][i]];
      }
    }

    int best_start = 0;
    int best_segments = n;

    for (int start = 0; start < n; ++start) {
      int target = start + n;
      int position = start;
      int segments = 0;

      for (int level = log - 1; level >= 0; --level) {
        int next_position = jump[level][position];

        if (next_position < target) {
          position = next_position;
          segments += 1 << level;
        }
      }

      ++segments;

      if (segments < best_segments) {
        best_segments = segments;
        best_start = start;
      }
    }

    // Recover the optimal circular rainbow partition.
    vector<int> boundary;
    boundary.push_back(best_start);

    int position = best_start;
    int target = best_start + n;

    while (position < target) {
      position = min(nxt[position], target);
      boundary.push_back(position);
    }

    int q = static_cast<int>(boundary.size()) - 1;

    if (q == 1) {
      cout << 0 << '\n';
      continue;
    }

    int k = (q + 1) / 2;
    cout << k << '\n';

    /*
     * Segment j begins at boundary[j] modulo n.
     *
     * Detector j covers k consecutive partition segments:
     *     j, j+1, ..., j+k-1  (mod q).
     *
     * Its circular endpoints are the starts of segment j and
     * segment (j+k) mod q.
     */
    for (int j = 0; j < k; ++j) {
      int start_boundary = boundary[j] % n;
      int end_boundary = boundary[(j + k) % q] % n;

      if (start_boundary < end_boundary) {
        // Direct non-wrapping arc.
        cout << start_boundary + 1 << ' ' << end_boundary << '\n';
      } else {
        /*
         * The desired circular arc wraps around.
         * Output its complement instead.
         * Complementing one report bit preserves uniqueness.
         */
        cout << end_boundary + 1 << ' ' << start_boundary << '\n';
      }
    }
  }

  return 0;
}
