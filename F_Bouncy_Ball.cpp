#include <bits/stdc++.h>
using namespace std;
#define DL 0
#define DR 1
#define UL 2
#define UR 3
vector<vector<vector<int>>> grid;
int r, c, u, v, i, j;
int dfs(int dir, int cx = u, int cy = v, int bounce = 0)
{
    // cout << dir << " " << cx << " " << cy << "\n";
    if (grid[cx][cy][dir] == 1)
        return -1;
    grid[cx][cy][dir] = 1;
    if (cx == i && cy == j)
        return bounce;
    if ((cx == 1 && cy == 1 && dir == UL) || (cx == 1 && cy == c && dir == UR) || (cx == r && cy == 1 && dir == DL) || (cx == r && cy == c && dir == DR))
        return dfs(dir ^ 3, cx, cy, bounce + 1);
    if (dir == DL)
        cx += 1, cy -= 1;
    else if (dir == DR)
        cx += 1, cy += 1;
    else if (dir == UL)
        cx -= 1, cy -= 1;
    else
        cx -= 1, cy += 1;
    if (!cx || !cy || cx == r + 1 || cy == c + 1)
    {
        if (cx == 0)
        {
            cx = 2;
            if (dir == 2)
                dir = 0;
            else if (dir == 3)
                dir = 1;
        }
        else if (cy == 0)
        {
            cy = 2;
            if (dir == 2)
                dir = 3;
            if (dir == 0)
                dir = 1;
        }
        else if (cx == r + 1)
        {
            cx = r - 1;
            if (dir == 1)
                dir = 3;
            else if (dir == 0)
                dir = 2;
        }
        else
        {
            cy = c - 1;
            if (dir == 3)
                dir = 2;
            else if (dir == 1)
                dir = 0;
        }
        bounce++;
    }
    return dfs(dir, cx, cy, bounce);
    return 0;
}

void solve()
{
    string dir;
    cin >> r >> c >> u >> v >> i >> j >> dir;
    grid = vector<vector<vector<int>>>(r + 1, vector<vector<int>>(c + 1, vector<int>(4, 0)));
    if (dir == "DL")
        cout << dfs(0) << "\n";
    else if (dir == "DR")
        cout << dfs(1) << "\n";
    else if (dir == "UL")
        cout << dfs(2) << "\n";
    else
        cout << dfs(3) << "\n";

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}