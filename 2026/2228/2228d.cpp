/*!
 * author: manhhomienbienthuy
 * created: 2026-06-30T01:16:23+00:00
 * https://codeforces.com/contest/2222/problem/D
 */

/*
Problem : Count distinct valid colorings from all(k1, k2) choices.

         Key insight : A "coloring" is fully determined by which gap k1 falls
                       in(between consecutive distinct x - values) and
   which gap k2 falls in(between consecutive distinct y - values)
       .Two different(gap_x, gap_y) pairs always produce different colorings,
because:
   - different gap_x → different set of L-points → some point changes color
   - same gap_x, different gap_y → some point changes top/bottom color

 So: answer = number of valid (gap_x, gap_y) pairs.

Parameterize:
 Let x-groups be g=0..mx-1 (sorted distinct x values).
 A valid x-split v ∈ {0..mx-2} means k1 in gap after x-group v, so:
   L = all points in groups 0..v, R = all points in groups v+1..mx-1.

 Similarly for y-splits j ∈ {1..py-1} where py = number of distinct y values.

For fixed x-split v, valid y-splits j are those where all 4 quadrants non-empty:
 1. Top-left: ∃ point in L with y > y_j   → maxY_L > y_j  → j < rank(maxY_L)
 2. Bottom-left: ∃ point in L with y ≤ y_j → minY_L ≤ y_j → j ≥ rank(minY_L)
 3. Top-right: ∃ point in R with y > y_j   → maxY_R > y_j  → j < rank(maxY_R)
 4. Bottom-right: ∃ point in R with y ≤ y_j → minY_R ≤ y_j → j ≥ rank(minY_R)

 Valid j range: lo = max(rank(minY_L), rank(minY_R)) ≤ j < hi =
min(rank(maxY_L), rank(maxY_R)) Count for this split = max(0, hi - lo)

Algorithm:
 1. Sort points by x. Build groups (each distinct x = one group with its minY,
maxY).
 2. Compute prefix min/max of y: pre[v] = (minY, maxY) over groups 0..v
 3. Compute suffix min/max of y: suf[v] = (minY, maxY) over groups v..mx-1
 4. Collect distinct y-values for ranking (binary search for rank).
 5. For each split v in 0..mx-2:
      lo = max(rank(pre[v].minY), rank(suf[v+1].minY))
      hi = min(rank(pre[v].maxY), rank(suf[v+1].maxY))
      ans += max(0, hi - lo)

Time: O(n log n) per test case.
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

    vector<pair<int, int>> pts(n);
    for (auto& [x, y] : pts) cin >> x >> y;
    sort(pts.begin(), pts.end());

    vector<int> gmn, gmx;
    int i = 0;
    while (i < n) {
      int j = i, cx = pts[i].first;
      int lo = pts[i].second, hi = pts[i].second;
      while (j < n && pts[j].first == cx) {
        lo = min(lo, pts[j].second);
        hi = max(hi, pts[j].second);
        j++;
      }
      gmn.push_back(lo);
      gmx.push_back(hi);
      i = j;
    }

    int mg = (int)gmn.size();
    vector<int> pmn(mg), pmx(mg);
    pmn[0] = gmn[0];
    pmx[0] = gmx[0];
    for (int i = 1; i < mg; i++) {
      pmn[i] = min(pmn[i - 1], gmn[i]);
      pmx[i] = max(pmx[i - 1], gmx[i]);
    }

    vector<int> smn(mg), smx(mg);
    smn[mg - 1] = gmn[mg - 1];
    smx[mg - 1] = gmx[mg - 1];
    for (int i = mg - 2; i >= 0; i--) {
      smn[i] = min(smn[i + 1], gmn[i]);
      smx[i] = max(smx[i + 1], gmx[i]);
    }

    vector<int> ys;
    ys.reserve(n);
    for (auto& [x, y] : pts) ys.push_back(y);
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    auto rk = [&](int y) {
      return (int)(lower_bound(ys.begin(), ys.end(), y) - ys.begin());
    };

    int64_t ans = 0;
    for (int v = 0; v < mg - 1; v++) {
      int lmn = rk(pmn[v]);
      int lmx = rk(pmx[v]);
      int rmn = rk(smn[v + 1]);
      int rmx = rk(smx[v + 1]);

      int lo = max(lmn, rmn) + 1;
      int hi = min(lmx, rmx);
      if (hi >= lo) ans += hi - lo + 1;
    }

    cout << ans << '\n';
  }

  return 0;
}
