#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n+1);
        for(int i=0; i<n; i++)
            cin >> v[i];
        v[n]=0;
        map<int, set<int>> mp;
        set<int> st;
        vector<int> ans(n);
        for(int i=0; i<n;  i++)
        {
            if(v[i]<v[i+1])
            {
                mp[v[i]].insert(i);
                st.insert(v[i]);
                while(1)
                {
                    auto it = st.begin();
                    if( it == st.end() || *it>=v[i+1])
                        break;
                    for(auto k: mp[*it])
                    {
                        ans[k]=mp[*it].size()-1;
                    }
                    st.erase(it);
                    mp[*it].clear();
                }
            }
            else 
            {
                mp[v[i]].insert(i);
                st.insert(v[i]);
            }
            // for(int i=0; i<n; i++)
            // cout << ans[i] << " \n"[i==n-1];
        }
        while(1)
        {
            auto it = st.begin();
            if( it == st.end())
                break;
            for(auto k: mp[*it])
            {
                ans[k]=mp[*it].size()-1;
            }
            st.erase(it);
            mp[*it].clear();
        }
        for(int i=0; i<n; i++)
            cout << ans[i] << " \n"[i==n-1];
    }
    return 0;
}