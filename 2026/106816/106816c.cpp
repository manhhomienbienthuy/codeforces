/*!
 * author: manhhomienbienthuy
 * created: 2026-11-09T08:30:15+00:00
 * https://codeforces.com/gym/106816/problem/3
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int F, N, T, V;
  cin >> F >> N >> T >> V;

  priority_queue<int64_t, vector<int64_t>, greater<>> pq;
  for (int i = 0; i < N; i++) pq.push(0);

  int64_t cash = 0;

  for (int i = 0; i < F; i++) {
    int64_t X;
    cin >> X;

    int64_t pump = pq.top();
    pq.pop();

    int64_t fuel = max(X, pump) + T;
    pq.push(fuel);

    int64_t out = cash = max(fuel, cash) + V;

    cout << out << '\n';
  }

  return 0;
}
