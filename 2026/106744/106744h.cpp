/*!
 * author: manhhomienbienthuy
 * created: 2026-10-07T01:06:27+00:00
 * https://codeforces.com/gym/106744/problem/H
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  priority_queue<int, vector<int>, greater<>> upper;
  priority_queue<int> lower;

  auto med = [&]() {
    if (upper.size() == lower.size())
      return (upper.top() + lower.top()) / 2;
    else if (upper.size() > lower.size())
      return upper.top();
    else
      return lower.top();
  };

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x <<= 1;

    if (upper.empty() || x > upper.top())
      upper.push(x);
    else
      lower.push(x);

    if (upper.size() - lower.size() == 2) {
      lower.push(upper.top());
      upper.pop();
    } else if (lower.size() - upper.size() == 2) {
      upper.push(lower.top());
      lower.pop();
    }

    cout << med() << ' ';
  }

  return 0;
}
