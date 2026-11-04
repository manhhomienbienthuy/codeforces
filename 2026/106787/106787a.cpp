/*!
 * author: manhhomienbienthuy
 * created: 2026-11-04T03:26:51+00:00
 * https://codeforces.com/gym/106787/problem/A
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> freq(26);
  vector<string> words(n);

  for (string& s : words) {
    cin >> s;
    for (char c : s) freq[c - 'a']++;
  }

  vector<pair<int, char>> letters;

  for (int i = 0; i < 26; i++) {
    letters.push_back({freq[i], char('a' + i)});
  }

  sort(letters.begin(), letters.end(), [](auto& x, auto& y) {
    return (x.first > y.first) || (x.first == y.first && x.second < y.second);
  });

  unordered_map<char, char> m;
  for (int i = 0; i < 26; i++) {
    m[letters[i].second] = letters[i % k].second;
  }

  for (string& s : words) {
    for (int i = 0; i < (int)s.size(); i++) s[i] = m[s[i]];
    cout << s << ' ';
  }
}
