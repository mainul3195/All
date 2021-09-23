#include<bits/stdc++.h>
using namespace std;
int n, m;
struct node{int u,v;};
vector<vector<int>>v, new_graph;
int dt;
vector<int> discoverty_time, low_time, visited, par;

int findPar(int u)
{
    if(par[u] == u)
        return u;
    return par[u] = findPar(par[u]);
}
void join(int u, int v)
{
    int pu = findPar(u);
    int pv = findPar(v);
    if(pu!=pv)
        par[u] = pv;
}
void find_artpoint(int u, int par)
{
    visited[u] = 1;
    discoverty_time[u] = low_time[u] = dt++;
    for(auto i: v[u])
    {
        if(i==par) continue;
        if(!visited[i]){ 
            find_artpoint(i,u);
            low_time[u] = min(low_time[u], low_time[i]);
        }
        else low_time[u] = min(low_time[u], discoverty_time[i]);
        if(discoverty_time[u]>=low_time[i])
            join(u,i);
    }
}
void find_new_graph(int u)
{
    visited[u] = 1;
    for(auto i: v[u])
    {
        if(!visited[i]){
            if(findPar(u)!=findPar(i))
            {               
                new_graph[findPar(u)].push_back(findPar(i));
                new_graph[findPar(i)].push_back(findPar(u));
            }
            find_new_graph(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc=0;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        v = vector<vector<int>>(n);
        new_graph = vector<vector<int>>(n+5);
        discoverty_time = vector<int>(n, 0);
        par = vector<int>();
        for(int i=0; i<n; i++)
            par.push_back(i);
        low_time = vector<int>(n, 0);
        for(int i=0; i<m; i++)
        {
            int x,y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dt = 1;
        visited = vector<int>(n, 0);
        find_artpoint(0, -1);
        visited = vector<int>(n, 0);
        find_new_graph(0);
        int col = 0;
        for(auto i: new_graph)
            if(i.size()==1)
                col++;


        cout << "Case " << ++tc << ": " << (col+1)/2 << "\n";
    }
    return 0;
}
