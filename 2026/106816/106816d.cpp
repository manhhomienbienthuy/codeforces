/*!
 * author: manhhomienbienthuy
 * created: 2026-11-10T03:28:43+00:00
 * https://codeforces.com/gym/106816/problem/4
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  int64_t sum = 1;

  for (int i = 0; i < N; i++) {
    int64_t ci;
    cin >> ci;

    sum += ci * ci;
  }

  cout << (int)sqrtl(sum) << '\n';
  return 0;
}
