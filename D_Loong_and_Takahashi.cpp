#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<pair<int, int>> dir = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}};
    int cur_dir = 0;
    int done = 0;
    int target = n * n - 1;
    int x = 0, y = 0;
    do
    {
        grid[x][y] = ++done;
        int nx = x + dir[cur_dir].first;
        int ny = y + dir[cur_dir].second;
        if (!(nx < 0 || ny < 0 || nx >= n || ny >= n || grid[nx][ny]))
            x = nx, y = ny;
        else
        {
            cur_dir = (cur_dir + 1) % 4;
            int nx = x + dir[cur_dir].first;
            int ny = y + dir[cur_dir].second;
            x = nx, y = ny;
        }
    } while (done < target);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == n / 2 && j == n / 2)
                cout << "T ";
            else
                cout << grid[i][j] << " \n"[j == n - 1];
        }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}