#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>vis;
int dfs(int u, int p = -1)
{
    int count = 1;
    vis[u] = 1;
    for(auto v: adj[u])
    {
        if(!vis[v] && v!=p)
            count+=dfs(v, u);
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        adj = vector<vector<int>>(n+1, vector<int>());
        vis = vector<int>(n+1, 0);
        int degree[n+1] = {0};
        for(int i = 1; i<=n; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        bool ok = 1;
        for(int i = 1; i<=n; i++)
        {
            if(degree[i]!=2)
            {
                ok = !ok;
                break;
            }
        }
        // for(int i = 1; i<=n; i++)
        //     cout << degree[i] << " \n"[i==n];
        // cout << ok << "\nbefore ->>\n";
        // for(int i = 0; i<=n; i++)
        //     cout << vis[i] << " ";cout <<"\nafter ->>\n";
        if(ok)
        {
            for(int i = 1; i<=n; i++)
                if(!vis[i])
                {
                    int nod = dfs(i);

                    // cout << i << " " << nod << "\n";
                    // for(int i = 0; i<=n; i++)
                    //     cout << vis[i] << " ";cout <<"\n";

                    if(nod%2)
                    {
                        ok = !ok;
                        break;
                    }
                }
        }
        if(ok)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}