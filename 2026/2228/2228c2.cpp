/*!
 * author: manhhomienbienthuy
 * created: 2026-06-16T10:59:11+00:00
 */

#include <bits/stdc++.h>
using namespace std;

string a;

string build_down(vector<char> d, int m) {
    int n = a.size();
    if (n == 1) {
        for (int i = m - 1; i >= 0; i--)
            if (d[i] <= a[0]) return string(1, d[i]);

        return string(1, d[0]);
    }

    string b(n, '0');

    for (int i = 0; i < n; i++) {
        char ca = -1;
        for (int j = m - 1; j >= 0; j--) {
            if (d[j] <= a[i]) {
                ca = d[j];
                break;
            }
        }

        if (ca == -1) {
            for (int j = i - 1; j >= 0; j--) {
                for (int x = m - 1; x >= 0; x--) {
                    if (b[j] > d[x]) {
                        b[j] = d[x];
                        for (int k = j + 1; k < n; k++) b[k] = d[m - 1];
                        return b;
                    }
                }
            }

            return string(n - 1, d[m - 1]);
        }

        b[i] = ca;
        if (ca < a[i]) {
            for (int j = i + 1; j < n; j++) b[j] = d[m - 1];
            return b;
        }
    }

    return b;
}

string build_up(vector<char> d, int m) {
    int n = a.size();
    string b(n, '0');

    for (int i = 0; i < n; i++) {
        char ca = -1;
        for (auto x : d) {
            if (x >= a[i]) {
                ca = x;
                break;
            }
        }

        if (ca == -1) {
            for (int j = i - 1; j >= 0; j--) {
                for (auto x : d) {
                    if (b[j] < x) {
                        b[j] = x;
                        for (int k = j + 1; k < n; k++) b[k] = d[0];
                        return b;
                    }
                }
            }

            b = string(n + 1, d[0]);
            if (d[0] == '0' && m > 1) b[0] = d[1];
            return b;
        }

        b[i] = ca;
        if (ca > a[i]) {
            for (int j = i + 1; j < n; j++) b[j] = d[0];
            return b;
        }
    }

    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> a >> n;
        vector<char> d(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            d[i] = '0' + x;
        }
        string down = build_down(d, n);
        string up = build_up(d, n);
        int64_t x = stoll(a), y = stoll(down), z = stoll(up);
        cout << min(abs(x - y), abs(x - z)) << "\n";
    }

    return 0;
}
