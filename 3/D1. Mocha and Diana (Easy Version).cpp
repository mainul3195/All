#include<bits/stdc++.h>
using namespace std;
vector<int>visited;
vector<int> p1, p2;
int par;
void dfs(vector<vector<int>>&v, int p, vector<int> &parent)
{
    visited[p] = 1;
    parent[p] = par;
    for(auto i: v[p])
        if(!visited[i])
            dfs(v, i, parent);
    return;
}
int getParent(int n, vector<int> &parent)
{
    if(parent[n]==n)
        return n;
    return parent[n] = getParent(parent[n], parent);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>> v1(n+1, vector<int>()), v2(n+1, vector<int>());
    for(int i=0; i<=n; i++)
    {
        p1.push_back(i);
        p2.push_back(i);
    }
    for(int i=0; i<m1; i++)
    {
        int u, v;
        cin >> u >> v;
        v1[u].push_back(v);
        v1[v].push_back(u);
    }
    for(int i=0; i<m2; i++)
    {
        int u, v;
        cin >> u >> v;
        v2[u].push_back(v);
        v2[v].push_back(u);
    }
    visited = vector<int>(n+1,0);
    for(int i=1; i<=n; i++)
        if(!visited[i])
        {
            par = i;
            dfs(v1,i, p1);
        }
    visited = vector<int>(n+1,0);
    for(int i=1; i<=n; i++)
        if(!visited[i])
        {
            par = i;
            dfs(v2,i, p2);
        }
    vector<pair<int, int>> ans;
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
        {
            int pu1 = getParent(i, p1);
            int pv1 = getParent(j, p1);
            int pu2 = getParent(i, p2);
            int pv2 = getParent(j, p2);
            if(pu1 != pv1 && pu2 != pv2) 
            {
                ans.push_back({i,j});
                p1[pu1] = pv1;
                p2[pu2] = pv2;
            }
        }
    cout << ans.size() << "\n";
    for(auto i: ans)
        cout << i.first << " " << i.second << "\n";
    return 0;
}