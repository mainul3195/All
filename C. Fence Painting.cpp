#include<bits/stdc++.h>
#define ll long long
#define vci vector<int>
#define vcll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mpii map<int, int>
#define mpll map<long long, long long>
using namespace std;
void solve()
{
    int m,n;
    cin >> n >> m;
    vci a(n), b(n), c(m);
    for(int i=0; i<n; i++)
        cin >>  a[i];
    map<int, int> pr;
    for(int i=0; i<n; i++)
    {
        cin >>  b[i];
        pr[b[i]]=i+1;
    }
    for(int i=0; i<m; i++)
    {
        cin >>  c[i];
    }
    map<int, multiset<int>> mp;
    int last = -1;
    for(int i=0; i<n; i++)
        if(a[i]!=b[i])
        {
            mp[b[i]].insert(i+1);
        }
    bool ok= 1 ;
    // cout << ok << " " << c[c.size()-1] << "\n";
    vci ans;
    if(ok){
        for(int i=0; i<m; i++)
        {
            int temp;
            if(!mp[c[i]].size())
            {
                if(!pr[c[i]])
                    temp = -1;
                else
                    temp = pr[c[i]];
            }
            else
            {
                auto it=mp[c[i]].begin();
                temp = *it;
                mp[c[i]].erase(it);
            }
            last = temp;
            ans.push_back(temp);
        }
        for(auto i:mp)
            if(i.second.size())
            {
                ok=0;
                break;
            }
    }
    if(!ok || last == -1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        for(int i=0; i<ans.size(); i++)
        {
            if(ans[i]==-1)
                cout << last;
            else 
                cout << ans[i];
            cout << " \n"[i==ans.size()-1];
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}