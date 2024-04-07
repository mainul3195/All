#include <bits/stdc++.h>
using namespace std;
int grundy[1000][1000], mark[10], x[] = {1, -1, -1, -2, -2, -3}, y[] = {-2, -3, -2, -1, 1, -1};
bool valid(int a, int b)
{
    return a >= 0 && b >= 0;
}
void calc_grundy()
{
    for (int m = 0; m < 999; m++)
    {
        int i = m;
        int j = 0;
        for (; valid(i, j); i--, j++)
        {
            memset(mark, 0, sizeof(mark));
            for (int k = 0; k < 6; k++)
            {
                int nx = i + x[k];
                int ny = j + y[k];
                if (valid(nx, ny))
                    mark[grundy[nx][ny]] = 1;
            }
            int k = 0;
            while (mark[k])
                k++;
            grundy[i][j] = k;
        }
    }
    return;
}
void solve()
{
    int n;
    cin >> n;
    int Xor = 0;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        Xor ^= grundy[x][y];
    }
    if (Xor)
        cout << "Alice\n";
    else
        cout << "Bob\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    calc_grundy();
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}