#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        vector<vector<ll>> pos(n + 1, vector<ll>(2, -1));
        for (ll i = n - 1; i >= 0; i--) {
            pos[i][0] = pos[i + 1][0];
            pos[i][1] = pos[i + 1][1];
            if (s[i] > 'a') pos[i][s[i] - 'b'] = i;
        }

        ll fb = pos[0][0], fc = pos[0][1];
        ll cnt_bc = 0, cnt_cb = 0, cnt_bca = 0, cnt_cba = 0;

        while (q--) {
            char x, y;
            cin >> x >> y;

            if (x == 'b' && y == 'a') {
                if (cnt_bca > 0) {
                    cnt_bca--;
                    cnt_bc++;
                    if (cnt_bc > 0 && fb > - 1 && (fb < fc || fc == -1)) {
                        cnt_bc--;
                        cnt_bca++;
                        s[fb] = 'a';
                        fb = pos[fb + 1][0];
                    } else if (fc != -1) {
                        s[fc] = 'a';
                        fc = pos[fc + 1][1];
                    }
                } else if (cnt_cb > 0 && fc > -1 && (fc < fb || fb == -1)) {
                    cnt_cb--;
                    cnt_cba++;
                    s[fc] = 'a';
                    fc = pos[fc + 1][1];
                } else if (fb != -1) {
                    s[fb] = 'a';
                    fb = pos[fb + 1][0];
                }
            } else if (x == 'c' && y == 'a') {
                if (cnt_cba > 0) {
                    cnt_cba--;
                    cnt_cb++;
                    if (cnt_cb > 0 && fc > -1 && (fc < fb || fb == -1)) {
                        cnt_cb--;
                        cnt_cba++;
                        s[fc] = 'a';
                        fc = pos[fc + 1][1];
                    } else if (fb != -1) {
                        s[fb] = 'a';
                        fb = pos[fb + 1][0];
                    }
                } else if (cnt_bc > 0 && fb > - 1 && (fb < fc || fc == -1)) {
                    cnt_bc--;
                    cnt_bca++;
                    s[fb] = 'a';
                    fb = pos[fb + 1][0];
                } else if (fc != -1) {
                    s[fc] = 'a';
                    fc = pos[fc + 1][1];
                }
            }
            else if (x == 'b' && y == 'c') cnt_bc++;
            else if (x == 'c' && y == 'b') cnt_cb++;
        }

        while (cnt_cb-- && fc != -1) {
            s[fc] = 'b';
            fc = pos[fc + 1][1];
        }
        cout << s << '\n';
    }

    return 0;
}
