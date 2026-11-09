/*!
 * author: manhhomienbienthuy
 * created: 2026-11-09T07:55:53+00:00
 * https://codeforces.com/gym/106816/problem/2
 */

#include <bits/stdc++.h>
using namespace std;

struct point {
  double x, y;

  point operator+(const point& p) const { return {x + p.x, y + p.y}; }

  point operator-(const point& p) const { return {x - p.x, y - p.y}; }

  point operator*(double k) const { return {x * k, y * k}; }
};

double mult(point a, point b) { return a.x * b.x + a.y * b.y; }

double cross(point a, point b) { return a.x * b.y - a.y * b.x; }

point reflect(point p, point a, point b) {
  point v = b - a;
  double t = mult(p - a, v) / mult(v, v);
  point h = a + v * t;

  return h * 2.0 - p;
}

point intersect(point a, point b, point p, point q) {
  point v = b - a;
  point u = q - p;

  double t = cross(a - p, v) / cross(u, v);

  return p + u * t;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  point A, B, C, D;

  cin >> A.x >> A.y;
  cin >> B.x >> B.y;
  cin >> C.x >> C.y;
  cin >> D.x >> D.y;

  double sc = cross(B - A, C - A);
  double sd = cross(B - A, D - A);

  point M;

  if (sc * sd < 0) {
    M = intersect(A, B, C, D);
  } else {
    point RC = reflect(C, A, B);
    M = intersect(A, B, RC, D);
  }

  cout << fixed << setprecision(10) << M.x << ' ' << M.y << '\n';

  return 0;
}
