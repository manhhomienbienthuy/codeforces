#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int f[26][26] = {0};
    for (int k = 0; k < n; k++) {
        char s[12];
        scanf("%s\n", &s);
        int len = strlen(s);
        int l = s[0] - 97;
        int r = s[len - 1] - 97;
        for (int i = 0; i < 26; i++) {
            if (f[i][l] > 0) {
                if (f[i][l] + len > f[i][r]) {
                    f[i][r] = f[i][l] + len;
                }
            }
        }
        if (len > f[l][r]) {
            f[l][r] = len;
        }
    }
    int result = 0;
    for (int i = 0; i < 26; i++) {
        if (f[i][i] > result) {
            result = f[i][i];
        }
    }
    printf("%d\n", result);
    return 0;
}
