#include<bits/stdc++.h>
using namespace std;
int h, w , x[]= {0, 1, 0, -1}, y[] = {1, 0, -1, 0};
vector<string> grid;
vector<vector<int>> vis;
bool inside(pair<int, int> p)
{
    if(p.first>=0 && p.second>=0 && p.first <h && p.second<w)
        return 1;
    return 0;
}
int dfs(pair<int, int> p)
{
    vis[p.first][p.second] = 1;
    int tot = 1;
    for (int i = 0; i < 4; i++)
    {
        int u = p.first + x[i];
        int v = p.second + y[i];
        if(inside({u, v}) && !vis[u][v] && grid[u][v]=='.')
            tot += dfs({u, v});
    }
    return tot;
}
void solve()
{
    cin >> w >> h;
    vis = vector<vector<int>>(h + 1, vector<int>(w + 1, 0));
    grid = vector<string>(h);
    for(auto &i: grid)
        cin >> i;
    pair<int, int> start;
    bool found = 0;
    for (int i = 0;!found && i < h; i++)
        for (int j = 0; j < w; j++)
            if(grid[i][j]=='@')
            {
                start = {i, j};
                found = 1;
                break;
            }
    cout << dfs(start) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, tc = 0;
    cin >> t;
    while(t--)
    {
        cout << "Case " << ++tc << ": ";
        solve(); 
    }
    return 0;
}

/*
gcd
lcm
modfact
fact
pfsingle
pfmultiple
ncrsingle
ncrmod
bgmod
mdinverse
sieve
SegmentTree
kmp
bit
sparseTable
vll
pi
ll
Pair
all
mll
mii
mis
msi
vvi
vi
pb
inf
linf
*/