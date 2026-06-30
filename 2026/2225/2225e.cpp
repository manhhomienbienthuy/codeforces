/*!
 * author: manhhomienbienthuy
 * created: 2026-06-30T09:03:41+00:00
 * https://codeforces.com/contest/2225/problem/E
 */

/*
Problem: Place non-overlapping radius-r circles (integer centers) covering ≥89%
of n uniformly-distributed points in an unknown rectangle.

=== Key Insight: Hexagonal Circle Packing ===

Hexagonal packing density = π/(2√3) ≈ 90.69% > 89%.

Place circles in a hexagonal grid:
 - Row spacing: dy = ceil(r*√3)  (ensures non-overlap between rows)
 - Even row j: centers at x0 + 2r*i   for i = 0,1,2,...
 - Odd  row j: centers at x0 + r + 2r*i

Non-overlap proof:
 - Same row: distance = 2r ✓
 - Adjacent rows: dist = √(r² + dy²) ≥ √(r² + 3r²) = 2r ✓ (since dy ≥ r√3)

Coverage: ~90.69% of area → ~90.69% of uniform points covered.
With n=10^4: σ ≈ 0.29%, so coverage is 90.69% ± ~0.9% (3σ) ≥ 89.79% >> 89%.

=== Algorithm ===
For each point (px, py):
 1. Find nearest hexagonal row: j0 = round((py - y0) / dy)
 2. Check rows j0-1, j0, j0+1
 3. In each row, find the nearest circle center (check i_near ± 1)
 4. If dist ≤ r, add that center to the output set

Output: only circles covering ≥1 point → at most n circles ✓

Circle center coordinates: within r of data points, so |cx|,|cy| ≤ 10^5+r ≤
2*10^5 ✓ Time: O(n log n)

=== Verify example ===
n=4, r=100, points: (0,0),(0,100),(100,0),(100,100)
dy = ceil(173.2) = 174, x0=0, y0=0

- (0,0): row j=0, cx=0 → circle (0,0), dist=0 ✓
- (0,100): row j=0, cx=0 → circle (0,0), dist=100 ✓
- (100,0): di=-1 → circle (0,0), dist=100 ✓
- (100,100): row j=1, cx=100, cy=174 → circle (100,174), dist=74 ✓

Output 2 circles: (0,0) and (100,174), both valid.
Non-overlap: √(10000+30276)=√40276≈200.69>200 ✓
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, r;
  cin >> n >> r;

  vector<int> px(n), py(n);
  for (int i = 0; i < n; i++) cin >> px[i] >> py[i];

  double sq3 = sqrt(3.0);
  int dy = (int)ceil(r * sq3);
  int dx = 2 * r;

  set<pair<int, int>> used;
  for (int p = 0; p < n; p++) {
    int qx = px[p], qy = py[p];
    int j_center = (int)round((double)qy / dy);
    pair<int, int> best = {INT_MAX, INT_MAX};
    int64_t best_dist2 = 1ll * (r + 1) * (r + 1);

    for (int dj = -1; dj <= 1; dj++) {
      int j = j_center + dj;
      int off = (j % 2 != 0) ? r : 0;
      int cy = j * dy;
      int i_near = (int)round((double)(qx - off) / dx);
      for (int di = -1; di <= 1; di++) {
        int i = i_near + di;
        int cx = off + i * dx;
        int64_t d2 = 1ll * (qx - cx) * (qx - cx) + 1ll * (qy - cy) * (qy - cy);
        if (d2 < best_dist2) {
          best_dist2 = d2;
          best = {cx, cy};
        }
      }
    }

    if (best_dist2 <= 1ll * r * r) {
      used.insert(best);
    }
  }

  cout << used.size() << "\n";
  for (auto [cx, cy] : used) cout << cx << " " << cy << "\n";

  return 0;
}
