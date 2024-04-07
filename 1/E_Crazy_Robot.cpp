#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> good;
int n, m, x[] = {1, 0, -1, 0}, y[] = {0, -1, 0, 1};
vector<string>grid;
pair<int, int> lab;
bool isgood(int tx, int ty)
{
    if(tx<0 || ty<0 || tx>=n || ty>=m || grid[tx][ty]=='L' || grid[tx][ty]=='+' || grid[tx][ty]=='#') return 0;
    int count = 0;
    for(int i = 0; i<4; i++)
    {
        int u = tx+x[i];
        int v = ty+y[i];
        if(u>=0 && v>=0 && u<n && v<m && grid[u][v]=='.')
            count ++;
    }
    if(count <= 1) return 1;
    return 0;
}
void bfs()
{
    queue<pair<int, int>>q;
    q.push(lab);
    while(q.size())
    {
        auto [u, v] = q.front();
        // cout << u << " " << v<< "\n";
        if(grid[u][v] == '.') grid[u][v] = '+';
        q.pop();
        for(int i = 0; i<4; i++)
        {
            int ux = u+x[i];
            int uy = v+y[i];
            // cout << "andhar -> " << ux << " " << uy << " " << (int)isgood(ux, uy) << "\n";
            if(isgood(ux, uy))
                q.push({ux, uy});
        }
    }
    return;
}
void solve()
{
    cin >> n >> m;
    grid = vector<string>(n);
    for(auto &i: grid)
        cin >> i;
    bool found = 0;
    for(int i = 0;!found && i<n; i++)
        for(int j = 0 ; j<m; j++)
            if(grid[i][j]=='L')
            {
                lab = {i, j};
                found = 1;
                break;
            }
    bfs();
    for(auto i: grid)
        cout << i << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve(); 
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