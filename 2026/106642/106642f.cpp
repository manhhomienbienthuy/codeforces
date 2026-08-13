/*!
 * author: manhhomienbienthuy
 * created: 2026-08-13T03:11:33+00:00
 * https://codeforces.com/gym/106642/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

const long double PI = acosl(-1.0L);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;

  cout << fixed << setprecision(15);

  while (tt--) {
    int alpha, beta, H;
    cin >> alpha >> beta >> H;

    /*
    h / x = tan(alpha)
    (H - h) / x = tan(beta)
    (H - h) / h = tan(beta) / tan(alpha)
    */

    long double ta = tan(alpha * PI / 180.0L);
    long double tb = tan(beta * PI / 180.0L);

    long double h = H / (1.0L + tb / ta);

    cout << h << '\n';
  }

  return 0;
}
