/*!
 * author: manhhomienbienthuy
 * created: 2026-06-16T06:18:13+00:00
 */

#include <bits/stdc++.h>
using namespace std;

string a;
char d1, d2;

string build_down() {
    int n = a.size();
    if (n == 1) {
        if (d2 <= a[0])
            return string(1, d2);
        else
            return string(1, d1);
    }

    string b(n, '0');

    for (int i = 0; i < n; i++) {
        char ca = -1;

        if (d2 <= a[i])
            ca = d2;
        else if (d1 <= a[i])
            ca = d1;

        if (ca == -1) {
            for (int j = i - 1; j >= 0; j--) {
                if (b[j] > d1) {
                    b[j] = d1;
                    for (int k = j + 1; k < n; k++) b[k] = d2;
                    return b;
                }
            }

            return string(n - 1, d2);
        }

        b[i] = ca;
        if (ca < a[i]) {
            for (int j = i + 1; j < n; j++) b[j] = d2;
            return b;
        }
    }

    return b;
}

string build_up() {
    int n = a.size();
    string b(n, '0');

    for (int i = 0; i < n; i++) {
        char ca = -1;

        if (d1 >= a[i])
            ca = d1;
        else if (d2 >= a[i])
            ca = d2;

        if (ca == -1) {
            for (int j = i - 1; j >= 0; j--) {
                if (b[j] < d2) {
                    b[j] = d2;
                    for (int k = j + 1; k < n; k++) b[k] = d1;
                    return b;
                }
            }

            b = string(n + 1, d1);
            if (d1 == '0') b[0] = d2;
            return b;
        }

        b[i] = ca;
        if (ca > a[i]) {
            for (int j = i + 1; j < n; j++) b[j] = d1;
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
        int n, u, v;
        cin >> a >> n >> u >> v;
        d1 = u + '0';
        d2 = v + '0';
        string down = build_down();
        string up = build_up();
        int64_t x = stoll(a), y = stoll(down), z = stoll(up);
        cout << min(abs(x - y), abs(x - z)) << "\n";
    }

    return 0;
}
