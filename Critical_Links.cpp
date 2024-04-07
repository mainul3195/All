#include<bits/stdc++.h>
using namespace std;
int  n, tim;
vector<vector<int>> adj;
vector<int> vis, dis, low;
vector<pair<int, int>>ab;
void dfs(int u, int p = -1)
{
    dis[u] = low[u] = ++tim;
    for(auto v: adj[u])
        if(v!=p)
        {
            if(!dis[v])
                dfs(v, u);
            low[u] = min(low[v], low[u]);
            if(p!=-1 && dis[u]<low[v])
                ab.push_back({min(u, v), max(u, v)});
            if(p == -1 && dis[v] == low[v])
                ab.push_back({min(u, v), max(u, v)});
        }
}
void solve()
{
    cin >> n;
    vis = vector<int> (n, 0);
    dis = vector<int> (n, 0);
    low = vector<int> (n, 0);
    tim = 0;
    ab.clear();
    adj = vector<vector<int>> (n, vector<int> ());
    for(int i = 0; i<n; i++)
    {
        int u, k;
        scanf("%d (%d)", &u, &k);
        while(k--)
        {
            int v;
            cin >> v;
            adj[u].push_back(v);
        }
    }
    for(int i = 0; i<n; i++)
        if(!dis[i])
            dfs(i);
    sort(ab.begin(), ab.end());
    cout << ab.size() << " critical links\n";
    for(auto [a, b]: ab)
        cout << a << " - " << b << "\n";
    return;
}
int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ":\n";
        solve();
    }
    return 0;
}