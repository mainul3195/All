#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int, long long>> node[30004];
vector<long long> vis(30004);
pair<int, long long> bfs(int n)
{
    queue<int> q;
    q.push(n);
    vis[n]=1;
    int mx=0, nd;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto i : node[u])
        {
            if(vis[i.first])
                continue;
            vis[i.first] = vis[u] + i.second;
            if(vis[i.first]>mx)
            {
                mx=vis[i.first];
                nd = i.first;
            }
            q.push(i.first);
        }
    }
    return {nd, mx};
}
int main()
{
    int t;
    cin >> t;
    int tc=0;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=0; i<=n; i++)
            node[i].clear();
        fill(vis.begin(), vis.end(), 0);

        for(int i=1; i<n; i++)
        {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            node[u].push_back({v, w});
            node[v].push_back({u, w});
        }

        pair<int, long long> p = bfs(0);
        fill(vis.begin(), vis.end(), 0);
        p=bfs(p.first);
        cout << "Case " << ++tc << ": " << p.second-1 << "\n";
    }
    return 0;
}