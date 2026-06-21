/*!
 * author: manhhomienbienthuy
 * created: 2026-06-17T00:00:06+00:00
 */

#include <bits/stdc++.h>
using namespace std;

void solve1(int);
void solve2(int);

int main() {
    string phase;
    cin >> phase;

    if (phase == "first") {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            int ok = 0;
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                if (x == 1)
                    ok ^= 1;
                else if (x == n)
                    ok = 1;
            }
            cout << ok << "\n";
        }
    } else {
        int t;
        cin >> t;
        while (t--) {
            int n, x;
            cin >> n >> x;
            if (x)
                solve1(n);
            else
                solve2(n);
        }
    }

    return 0;
}

bool ask(int l, int r, int n) {
    cout << "? " << l << " " << r << "\n";
    int x;
    cin >> x;
    return x == (n - 1);
}

void solve1(int n) {
    int l = 1, r = n;
    while (l <= r) {
        int m = (l + r) / 2;
        if (ask(1, m, n))
            r = m - 1;
        else
            l = m + 1;
    }
    cout << "! " << l << "\n";
}

void solve2(int n) {
    int l = 1, r = n;
    while (l <= r) {
        int m = (l + r) / 2;
        if (ask(m, n, n))
            l = m + 1;
        else
            r = m - 1;
    }
    cout << "! " << r << "\n";
}
