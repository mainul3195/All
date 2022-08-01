#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
void solve()
{
    int m;
    cin >> m;
    adj = vector<vector<int>>(20004, vector<int>());
    vector<int> indegree(20004, 0);
    map<string, int> mp;
    int tkn = 0;
    for(int i = 0; i<m; i++)
    {
        string u, v;
        cin >> u >> v;
        if(mp.count(u)==0)
            mp[u] = tkn++;
        if(mp.count(v)==0)
            mp[v] = tkn++;
        adj[mp[u]].push_back(mp[v]);
        indegree[mp[v]]++;
    }
    queue<int>inzero;
    for(int i = 0; i<tkn; i++)
        if(!indegree[i])
            inzero.push(i);
    int count = 0;
    while(inzero.size())
    {
        int f = inzero.front();
        inzero.pop();
        count++;
        for(auto v: adj[f])
        {
            indegree[v]--;
            if(!indegree[v])
                inzero.push(v);
        }
    }
    if(count==tkn)
        cout << "Yes\n";
    else cout << "No\n";
    return;
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