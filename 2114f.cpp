#include <bits/stdc++.h>
using namespace std;

int gcd(int a , int b)
{
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int calc(int n, int k) {
    if (n == 1) return 0;
    if (n <= k) return 1;

    set<int> f;
    vector<int> dp(n + 1, -1);
    for (int i = 2; i <= k; i++) {
        if (n % i == 0) {
            dp[i] = 1;
            f.insert(i);
        }
    }
    if (f.empty()) return -1;

    set<int> cur = f;
    while (!cur.count(n)) {
        set<int> nxt;
        for (auto i : f) {
            for (auto j : cur) {
                int z = i * j;
                if (z > n || z <= k || n % z > 0) continue;
                nxt.insert(z);
                if (dp[z] == -1) {
                    dp[z] = dp[j] + 1;
                }
                else {
                    dp[z] = min(dp[z], dp[j] + 1);
                }
            }
        }
        if (nxt.empty()) return -1;
        cur = nxt;
    }

    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;

        int g = gcd(x, y);

        int m = y / g;
        int n = x / g;

        int s1 = calc(m, k);
        int s2 = calc(n, k);

        if (s1 < 0 || s2 < 0) {
            cout << -1 << "\n";
        } else {
            cout << s1 + s2 << "\n";
        }
    }

    return 0;
}
