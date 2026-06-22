/*!
 * author: manhhomienbienthuy
 * created: 2026-06-19T09:20:22+00:00
 * https://codeforces.com/contest/2237/problem/G
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int primes[] = {
        2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,
        47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107,
        109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
        191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
        269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
        353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
        439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521,
        523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613,
        617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
        709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
        811, 821, 823, 827, 829, 839, 853, 857, 859, 863};

    int g[150];
    for (int i = 0; i < 150; i++) {
        int p = primes[i];
        int x = p;
        while (x * p < 1e6) x *= p;
        g[i] = x;
    }

    vector<int> enc;
    int nn = enc.size();
    int idx = -1;
    while (nn < (1 << 18)) {
        int p = primes[++idx];
        for (int x = p; x < 1e6 && enc.size() < (1 << 18); x *= p) {
            enc.push_back(x);
            for (int j = 0; j < nn; j++) {
                int64_t y = 1ll * x * enc[j];
                if (y < 1e6) enc.push_back(y);
            }
        }
        nn = enc.size();
    }

    unordered_map<int, int> dec;
    for (idx = 0; idx < nn; idx++) {
        dec[enc[idx]] = idx;
    }

    string phase;
    cin >> phase;
    if (phase == "first") {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<int> b;
            while (n--) {
                int x;
                cin >> x;
                for (int i = 0; i < 20; i++) {
                    b.push_back((x >> i) & 1);
                }
            }
            while (b.size() % 18) b.push_back(0);
            n = b.size();
            vector<int> send;
            for (int i = 0; i < n; i += 18) {
                int x = 0;
                for (int j = 0; j < 18; j++) {
                    x |= b[i + j] << j;
                }
                send.push_back(enc[x]);
            }
            cout << 150 + send.size() << "\n";
            for (auto x : g) cout << x << " ";
            for (auto x : send) cout << x << " ";
            cout << "\n";
        }
    } else {
        int t;
        cin >> t;
        while (t--) {
            int n, k;
            cin >> n >> k;
            vector<int> b;
            for (int i = 150; i < k; i++) {
                int x = 1;
                for (int j = 0; j < 150; j++) {
                    cout << "? " << j + 1 << " " << i + 1 << "\n";
                    int y;
                    cin >> y;
                    x *= y;
                }
                x = dec[x];
                for (int j = 0; j < 18; j++) {
                    b.push_back((x >> j) & 1);
                }
            }
            while (b.size() % 20) b.pop_back();
            vector<int> a;
            for (int i = 0; i < b.size(); i += 20) {
                int x = 0;
                for (int j = 0; j < 20; j++) {
                    x |= b[i + j] << j;
                }
                a.push_back(x);
            }
            cout << "! ";
            for (int x : a) cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}
