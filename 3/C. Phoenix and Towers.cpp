#include<bits/stdc++.h>
using namespace std;
struct pr
{
    int val, ind;
    bool operator < (const pr &a)const
    {
        return val<a.val ||(val == a.val && ind<a.ind);
    }
};
vector<int>par;
int getpar(int u)
{
    if(par[u]==u) return u;
    return par[u] = getpar(par[u]);
}
void join(int u, int v)
{
    int pu = getpar(u);
    int pv = getpar(v);
    par[u]=pv;
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, x;
        cin >>  n >> m >> x;
        par.clear();
        for(int i=0; i<=n; i++)
            par.push_back(i);
        vector<pr>v;
        for(int i=0; i<n; i++)
        {
            int j;
            cin >> j;
            v.push_back({j,i});
        }
        sort(v.begin(), v.end());
        set<pair<int, int>>st;
        int i,count;
        for(i=n-1, count = 0; count<m; i--, count++)
            st.insert({v[i].val, v[i].ind});
        // for(auto it = st.begin(); it!=st.end(); it++)
        //     cout << (*it).first << " " << (*it).second << "\n";
        for(; i>=0; i--)
        {
            auto it = st.begin();
            join(v[i].ind, (*it).second);
            st.insert({(*it).first+v[i].val, (*it).second});
            st.erase(it);
        }
        for(i=0; i<=n; i++) getpar(i);
        // for(auto j: par)
        //     cout << j << " ";
        //     cout << "\n";
        // for(auto j: st)
        //     cout << j.first << " " << j.second << "\n";
        set<int>p;
        for(i=0; i<n; i++)
            p.insert(par[i]);
        map<int, int>mp;
        int tmp= 1;
        for(auto i: p)
            mp[i] = tmp++;
        cout << "YES\n";
        for(i = 0; i<n; i++)
            cout << mp[par[i]] << " \n"[i==n-1];
    }
    return 0;
}