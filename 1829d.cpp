#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        bool ok = false;
        stack<int> s; s.push(n);
        while (!s.empty()) {
            int x = s.top(); s.pop();
            if (x == m) {
                ok = true;
                break;
            } else if (x < m || x % 3) {
                continue;
            } else {
                int y = x / 3, z = x / 3 * 2;
                s.push(y);
                s.push(z);
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
