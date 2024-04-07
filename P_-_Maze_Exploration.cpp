#include <bits/stdc++.h>
using namespace std;
string s;
vector<string> grid;
int x[] = {1, 0, -1, 0}, y[] = {0, -1, 0, 1};
void dfs(int i, int j)
{
    grid[i][j] = '#';
    for (int k = 0; k < 4; k++)
    {
        int r = i + x[k];
        int c = j + y[k];
        if (r >= 0 && c >= 0 && r < grid.size() && c < grid[r].size() && grid[r][c] == ' ')
            dfs(r, c);
    }
}
void solve()
{
    grid.clear();
    do
    {
        getline(cin, s);
        grid.push_back(s);
    } while (s[0] != '_');
    bool ok = 1;
    for (int i = 0; ok && i < grid.size(); i++)
        for (int j = 0; ok && j < grid[i].size(); j++)
        {
            if (grid[i][j] == '*')
            {
                dfs(i, j);
                ok = !ok;
            }
        }
    for (auto v : grid)
        cout << v << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    getline(cin, s);
    while (t--)
        solve();
    return 0;
}