#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
int vis[200005];
set<int> st;
int dfs(int u, int p = -1)
{
    // cout << u << " -> \n";
    vis[u] = 1;
    int count = 0;
    for(auto v: adj[u])
    {
        if(!vis[v] && v!=p)
        {
            int state = dfs(v, u);
            if(state==-1)
                return -1;
            count+= state;
        }
    }

    if(u==*(st.begin()))
    {
        if(count>2)
            return -1;
        return 1;
    }
    
    if(count>1)
        return -1;
    return count | (st.find(u)!=st.end());

}
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, q;
    cin >> n;
    adj = vector<vector<int>>(n+1, vector<int>());
    for(int i = 1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> q;
    while(q--)
    {
        int k;
        cin >> k;
        memset(vis, 0, n+2);
        for(int i = 1; i<=n; i++)
            vis[i] = 0;
        st.clear();
        bool ok = 1;
        while(k--)
        {
            int nd;
            cin >> nd;
            st.insert(nd);
        }
        if(st.size()==1)
        {
            cout << "YES\n";
            continue;
        }
        if(dfs(*(st.begin()))!=-1)
            cout << "YES\n";
        else cout << "NO\n";
        // for(int i = 1; i<=n; i++)
        //     cout << vis[i] << " ";
        //     cout << "\n";
    }

    return 0;
}