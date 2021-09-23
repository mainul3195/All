#include<bits/stdc++.h>
#define Swap(x,y) x^=y^=x^=y
using namespace std;
vector<vector<int>>v;
vector<int>par,level;
int n;
void dfs(int u = 1, int p = -1, int l = 0)
{
    par[u] = p;
    level[u] = l;
    for(auto i: v[u])
        if(i!=p)
            dfs(i,u,l+1);
}

vector<vector<int>>sparce;
void lca_init()
{
    for(int i=1; i<=n; i++)
        sparce[i][0] = par[i];

    for(int j=1; (1<<j) <= n; j++)
        for(int i=1; i<=n; i++)
            if(sparce[i][j-1]!=-1)
                sparce[i][j] = sparce[sparce[i][j-1]][j-1];
    
}
int lca_query(int u, int v)
{
    if(level[u]<level[v])
        Swap(u,v);
    for(int i = log2(n)+1; i>=0; i--)
        if(level[u]-(1<<i)>=level[v])
            u = sparce[u][i];
    if(u==v) return u;
    for(int i = log2(n)+1; i>=0; i--)
        if(sparce[u][i] != -1 && sparce[u][i] != sparce[v][i])
            u = sparce[u][i], v = sparce[v][i];
    return par[u];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc=0;
    cin >> t;
    while(t--)
    {
        cout << "Case " << ++tc << ":\n";
        cin >> n;
        v = vector<vector<int>>(n+1);
        par = vector<int>(n+1);
        level = vector<int>(n+1, -1);
        sparce = vector<vector<int>>(n+1, vector<int>(log2(n)+2, -1));
        for(int i=1; i<=n; i++)
        {
            int m;
            cin >> m;
            while(m--)
            {
                int j;
                cin >> j;
                v[j].push_back(i);
                v[i].push_back(j);
            }
        }
        dfs();
        // for(auto i: par)
        //     cout << i << " ";
        //     cout << "\n";
        lca_init();
        int q;
        cin >> q;
        while(q--)
        {
            int i, j;
            cin >> i >> j;
            cout<< lca_query(i,j) << "\n";
        }
    }
    return 0;
}