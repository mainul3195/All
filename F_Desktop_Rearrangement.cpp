#include <bits/stdc++.h>
using namespace std;
int n, m, q;
vector<string> grid;
vector<long long> x_dir;
vector<vector<long long>>y_dir;
long long x_qr(long long x)
{
    long long ans = 0;
    for (; x > 0; x -= (x & (-x)))
        ans += x_dir[x];
    return ans;
}
void x_upd(long long x, long long val)
{
    for (; x <= m; x += (x & (-x)))
        x_dir[x] += val;
}
long long y_qr(long long x, int col)
{
    long long ans = 0;
    for (; x > 0; x -= (x & (-x)))
        ans += y_dir[col][x];
    return ans;
}
void y_upd(long long x, long long val, int col)
{
    for (; x <= n; x += (x & (-x)))
        y_dir[col][x] += val;
}
void solve()
{
    cin >> n >> m >> q;
    grid = vector<string>(n);
    x_dir = vector<long long>(m+5, 0);
    y_dir = vector<vector<long long>>(m+2, vector<long long>(n+5, 0));
    for (auto &i : grid)
        cin >> i;
    int tot = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '*')
            {
                tot++;
                x_upd(j + 1, 1);
                y_upd(i + 1, 1, j);
            }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (grid[x][y] == '*')
        {
            tot--;
            grid[x][y] = '.';
            x_upd(y + 1, -1);
            y_upd(x + 1, -1, y);
        }
        else
        {
            tot++;
            grid[x][y] = '*';
            x_upd(y + 1, 1);
            y_upd(x + 1, 1, y);
        }
        int len_of_x_dir = tot / n;
        int ans = len_of_x_dir * n - x_qr(len_of_x_dir);
        int len_of_y_dir = tot % n;
        ans += len_of_y_dir - y_qr(len_of_y_dir, len_of_x_dir);
        cout << ans << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}