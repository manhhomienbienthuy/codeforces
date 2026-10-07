/*!
 * author: manhhomienbienthuy
 * created: 2026-10-07T10:22:23+00:00
 * https://codeforces.com/gym/106744/problem/F
 */

#include <bits/stdc++.h>
using namespace std;

int calc(const string& date, const string& time) {
  int mon = stoi(date.substr(0, 2)), day = stoi(date.substr(3, 2)),
      hour = stoi(time.substr(0, 2)), min = stoi(time.substr(3, 2)),
      sec = stoi(time.substr(6, 2));

  int days = day - 1;

  if (mon == 7)
    days += 30;
  else if (mon == 8)
    days += 61;

  return days * 86400 + hour * 3600 + min * 60 + sec;
  ;
}

int id(char a) {
  if (a == 'S') return 0;
  if (a == 'W') return 1;
  if (a == 'T') return 2;
  return 3;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int64_t> ans(4);

  int prev = 0;
  char prev_a = 'S';

  for (int i = 0; i < n; i++) {
    string date, time;
    char cur_a;

    cin >> date >> time >> cur_a;

    int cur = calc(date, time);

    if (i > 0) {
      ans[id(prev_a)] += cur - prev;
    }

    prev = cur;
    prev_a = cur_a;
  }

  ans[id(prev_a)] += 92 * 24 * 60 * 60 - prev;

  string name = "SWTR";

  for (int i = 0; i < 4; i++) {
    int64_t days = ans[i] / 86400, rem = ans[i] % 86400, hour = rem / 3600,
            min = rem % 3600 / 60, sec = rem % 60;

    cout << name[i] << ' ' << days << ' ' << setfill('0') << setw(2) << hour
         << ':' << setw(2) << min << ':' << setw(2) << sec << '\n';
  }

  return 0;
}
