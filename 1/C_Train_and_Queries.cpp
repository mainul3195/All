#include<bits/stdc++.h>
using namespace std;
map<int, set<int>>mp;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, q;
        cin >> n >> q;
        mp.clear();
        for(int i = 0; i<n; i++)
        {
            int stn;
            cin >> stn;
            mp[stn].insert(i);
        }
        while(q--)
        {
            int l, r;
            cin >> l >> r;
            if(mp.count(l)==0 || mp.count(r)==0)
            {
                cout << "NO\n";
                continue;
            }
            int strt = *(mp[l].begin());
            auto it = mp[r].end();
            int end = *(--it);
            if(strt<=end)
                cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}