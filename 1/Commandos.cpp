#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> diss, disd;
int n, m;
void bfs(int source, vector<int>&dis)
{
    dis[source] = 0;
    queue<int> q;
    q.push(source);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(auto v: adj[u])
        {
            if(dis[v]==-1)
            {
                dis[v] = dis[u] +1;
                q.push(v);
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n, vector<int>());
    for(int i = 0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s, d;
    cin >> s >> d;
    diss = vector<int>(n, -1);
    disd = vector<int>(n, -1);
    bfs(s, diss);
    bfs(d, disd);
    int ans = 0;
    for(int i = 0; i<n; i++)
        ans = max(ans, diss[i]+disd[i]);
    cout << ans << "\n";

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i<=t; i++)
    {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}