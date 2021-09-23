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
    int n;
    cin >> n;
    vector<long long> v(n+2);
    mpll mp;
    ll tot = 0;
    for(auto &i: v)
    {
        cin >> i;
        tot += i;
        mp[i]++;
    }
    long long sum , extra;
    bool found = 0;
    for(int i=0; i<n+2; i++)
    {
        long long need = tot - 2*v[i];
        if(need == v[i] && mp[need]==1) continue;
        if(mp[need])
        {
            found = 1;
            sum = v[i];
            extra = need;
            break;
        }
    }
    if(!found)
        cout << "-1\n";
    else
    {
        int count = 0;
        bool sumfound=0, extrafound = 0;
        for(auto i: v)
        {
            if(!sumfound && i==sum)
            {
                sumfound = 1;
                continue;
            }
            if(!extrafound && i==extra)
            {
                extrafound = 1;
                continue;
            }
            count ++;
            cout << i << " \n"[count == n];
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