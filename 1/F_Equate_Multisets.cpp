#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        multiset<int>sta;
        vector<int>stb(n);
        int mx = 0;
        for(int i = 0; i<n; i++)
        {
            int v;
            cin >> v;
            while(v%2==0)
                v>>=1;
            mx = max(mx, v);
            sta.insert(v);
        }
        int mn = ULLONG_MAX;
        for(auto &i: stb)
        {
            cin >> i;
            mn = min(mn, i);
        }
        int mul = 1;
        while(mn<=mx)
        {
            mn = mn*2;
            mul*=2;
        }
        for(auto &i: stb)
            i*=mul;
        // for(auto i: stb)
        //     cout <<  i << " ";
        //     cout << "\n";
        bool ok = 1;
        for(auto &i: stb)
        {
            // cout << "from here -> " << i << "\n";
            while(i)
            {
                // cout << i << " ";
                auto it = sta.find(i);
                if(it!=sta.end())
                {
                    sta.erase(it);
                    break;
                }
                i>>=1;
            }
            if(!i)
            {
                ok = !ok;
                break;
            }
            // cout << "\n";
        }
        if(ok)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}