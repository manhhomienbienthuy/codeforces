#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, l, k;
        cin >> n >> l >> k;

        string s;
        cin >> s;

        int limit = n - k * l;
        if (limit < 0) {
            cout << "NO\n";
            continue;
        }

        if (k == 1) {
            cout << "YES\n" << s << "\n";
            continue;
        }

        int left = 0;

        for (int i = l; i < n - l + 1; i += l) {
            for (int j = i; j < min(i + limit + 1, n - l + 1); ++j) {
                int max_k = min(l + limit - (j % l), n - j);
                for (int kk = 0; kk < max_k; ++kk) {
                    if (s[j + kk] > s[left + kk]) {
                        left = j;
                        break;
                    }
                    if (s[j + kk] < s[left + kk]) {
                        break;
                    }
                }
            }
        }

        cout << "YES\n";
        int right = left + l + limit - (left % l);
        cout << s.substr(left, right - left) << "\n";
    }

    return 0;
}
