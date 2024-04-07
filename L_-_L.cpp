#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5e5 + 5;
const int MAXK = 10;

int k, n;
char s[MAXN], t[MAXN];
int f[MAXN][MAXK + 1][2];

int main() {
    cin >> k >> s;
    n = strlen(s);
    reverse(s, s + n);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            f[i][j][0] = f[i][j][1] = n;

    f[0][0][0] = f[0][0][1] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int p = 0; p <= 1; p++) {
                if (f[i][j][p] == n) continue;

                if (s[i] == t[i]) {
                    f[i + 1][j][p] = min(f[i + 1][j][p], f[i][j][p]);
                } else {
                    f[i + 1][j + 1][p] = min(f[i + 1][j + 1][p], f[i][j][p] + 1);
                }

                if (j < k) {
                    if (s[i] == t[n - j - 1]) {
                        f[i + 1][j + 1][1] = min(f[i + 1][j + 1][1], f[i][j][p]);
                    } else {
                        f[i + 1][j + 1][1] = min(f[i + 1][j + 1][1], f[i][j][p] + 1);
                    }
                }
            }
        }
        t[i] = s[n - i - 1];
    }

    if (f[n][k][0] == n) {
        cout << "impossible" << endl;
    } else {
        cout << f[n][k][0] << endl;
    }

    return 0;
}
