#include<bits/stdc++.h>
using namespace std;
int  n, tim, m;
vector<vector<int>> adj;
vector<int> vis, dis, low;
vector<int>ap;
void dfs(int u, int p = -1)
{
    int child = 0;
    dis[u] = low[u] = ++tim;
    for(auto v: adj[u])
        if(v!=p)
        {
            if(dis[v])
                low[u] = min(low[u], dis[v]);
            else
            {
                dfs(v, u);
                low[u] = min(low[v], low[u]);
                if(p!=-1 && dis[u]<=low[v])
                    ap.push_back(u);
                else child++;
            }
        }
    if(p == -1 && child>1)
        ap.push_back(u);
}
void solve()
{
    cin >> n >> m;
    vis = vector<int> (n+1, 0);
    dis = vector<int> (n+1, 0);
    low = vector<int> (n+1, 0);
    tim = 0;
    ap.clear();
    adj = vector<vector<int>> (n+1, vector<int> ());
    for(int i = 0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i<=n; i++)
        if(!dis[i])
            dfs(i);
    set<int>s(ap.begin(), ap.end());
    cout << s.size() << "\n";
    // for(auto i: ap)
    //     cout << i << " ";
    //     cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}