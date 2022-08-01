#include <bits/stdc++.h>
using namespace std;
int row, col, x[] = {0, 1, 0, -1}, y[] = {1, 0, -1, 0};
vector<vector<int>> grid;
pair<int, int> source, dest;
bool inside(int a, int b)
{
    if (a >= 0 && b >= 0 && a < row && b < col)
        return 1;
    return 0;
}
int bfs()
{
    queue<pair<int, int>> q;
    grid[source.first][source.second] = 0;
    q.push(source);
    while (q.size())
    {
        pair<int, int> u = q.front();
        q.pop();
        if (u == dest)
            return grid[u.first][u.second];
        for (int i = 0; i < 4; i++)
        {
            int vx = u.first + x[i];
            int vy = u.second + y[i];
            if (inside(vx, vy) && grid[vx][vy] == -1)
            {
                grid[vx][vy] = grid[u.first][u.second] + 1;
                q.push({vx, vy});
            }
        }
    }
    return grid[dest.first][dest.second];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> row >> col && (row || col))
    {
        int bombed_row;
        cin >> bombed_row;
        grid = vector<vector<int>>(row, vector<int>(col, -1));
        while (bombed_row--)
        {
            int row_num, bombed_num;
            cin >> row_num >> bombed_num;
            while (bombed_num--)
            {
                int bombed_col;
                cin >> bombed_col;
                grid[row_num][bombed_col] = 0;
            }
        }
        cin >> source.first >> source.second >> dest.first >> dest.second;
        cout << bfs() << "\n";
    }

    return 0;
}