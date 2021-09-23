#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> vis(10004);
vector<int> node[10001];

pair<int, int> bfs(int n)
{
    queue<int> q;
    q.push(n);
    int mx=1, last=n;
    vis[n]=1;
    while(!q.empty())
    {
        int u= q.front();
        q.pop();
        for(auto i: node[u])
        {
            if(vis[i])
                continue;
            vis[i]= vis[u]+1;
            if(vis[i]>mx)
            {
                mx=vis[i];
                last = i;
            }
            q.push(i);
        }
    }
    return {mx,last};
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    fill(vis.begin(), vis.begin()+n+1, 0);
    for(int i=0; i<=n; i++)
        node[i].clear();
    for(int i=1; i<n; i++)
    {
        int u,v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    pair<int, int> p = bfs(1);
    fill(vis.begin(), vis.begin()+n+1, 0);
    p = bfs(p.second);
    cout << p.first - 1 << "\n";
    return 0;
}