#include <bits/stdc++.h>
using namespace std;
vector<string> grid;
int w, h;
bool isvalid(int &i, int &j)
{
    if (i >= 0 && j >= 0 && i < h && j < w && grid[i][j] == '.')
        return 1;
    return 0;
}
int x[] = {1, 0, -1, 0}, y[] = {0, -1, 0, 1};
int dfs(int i, int j)
{
    if (!isvalid(i, j))
        return 0;
    grid[i][j] = '#';
    int ans = 0;
    for (int k = 0; k < 4; k++)
        ans += dfs(i + x[k], j + y[k]);
    return 1 + ans;
}
void solve()
{
    cin >> w >> h;
    grid = vector<string>(h);
    for (auto &i : grid)
        cin >> i;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (grid[i][j] == '@')
            {
                grid[i][j] = '.';
                cout << dfs(i, j) << "\n";
                return;
            }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}