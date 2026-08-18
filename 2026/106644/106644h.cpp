#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;

  while (tt--) {
    int n;
    string s;

    cin >> n >> s;

    bool ok;

    if (n % 2 == 0) {
      int m = n / 2;
      ok = (s[m - 1] == 'B' || s[m] == 'B');
    } else {
      int m = n / 2;
      ok = (s[m] == 'B') && (s[m - 1] == 'B' || s[m + 1] == 'B');
    }

    cout << (ok ? "Doludu" : "DoIudu") << '\n';
  }

  return 0;
}
