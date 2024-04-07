#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
double dfs(int u = 1, int par = -1)
{
    double tot = 0;
    int count = 0;
    for(auto v: adj[u])
        if(v!=par)
        {
            tot += dfs(v, u) + 1;
            count++;
        }
    if(!count)
        return 0.0;
    return tot/count;
}
void solve()
{
    cin >> n;
    adj = vector<vector<int>> (n+1, vector<int> ());
    for(int i = 1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << fixed << setprecision(8) << dfs() << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
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