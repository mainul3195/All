#include <bits/stdc++.h>
using namespace std;
int h, w;
vector<string> grid;
void Float(int i, int j)
{
    int pos = i - 1;
    for (; pos >= 0 && grid[pos][j] == '*'; pos--)
        ;
    if(grid[pos+1][j]=='*')
        swap(grid[pos + 1][j], grid[i][j]);
    return;
}
void solve()
{
    cin >> h >> w;
    grid = vector<string>(h);
    for (auto &i : grid)
        cin >> i;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if(grid[i][j]=='.')
                Float(i, j);
    for(auto &i: grid)
        cout << i << "\n";
            return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}