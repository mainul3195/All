#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> adj;
set<int> non;
map<int, int> vis;
int s, d;
int bfs(int u, int power)
{
    queue<int> q;
    q.push(u);
    vis.clear();
    vis[u] = power;
    while(q.size())
    {
        int from = q.front();
        q.pop();
        if(!vis[from])
            continue;
        for(auto to: adj[from])
            if(vis.find(to)==vis.end())
            {
                vis[to] = vis[from] - 1;
                q.push(to);
            }
    }
    return vis.size();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, tc = 0;
    while (cin >> n && n)
    {
        non.clear();
        adj.clear();
        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            non.insert(u);
            non.insert(v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        while (cin >> s >> d && (s || d))
            cout << "Case " << ++tc << ": " << (non.find(s)==non.end()? non.size(): non.size()- bfs(s, d)) << " nodes not reachable from node " << s << " with TTL = " << d << ".\n";
    }
    return 0;
}