#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v)
        cin >> i;
    bool ok = 1;
    int ans = -1;
    for(auto a: v)
    {
        int samecount = 0;
        for(auto i: v)
            if(i==a)
                samecount++;
        if(samecount>=n/2)
        {
            ok = 0;
            break;
        }
        map<int, int>mp;
        // cout << "\n****" << a << "->\n";
        for(auto i: v)
            if(i>a)
            {
                // cout << i << " -> \n";
                int dif = i-a;
                int rt = (sqrt(dif)+.0000001);
                for(int j = 1; j<=rt; j++)
                    if(!(dif%j))
                    {
                        mp[j]++;
                        if(j!=(dif/j))
                            mp[dif/j]++;
                        // cout << j << " " << dif/j << "\n";
                    }
                for(auto [div, count]: mp)
                    if(count>= (n/2)-samecount)
                    {
                        ans = max(ans, div);
                        // cout << a << " -> " << div << " " << ans << "\n";
                    }
            }
    }
    if(ok)
        cout << ans << "\n";
    else cout << "-1\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve(); 
    return 0;
}

/*
gcd
lcm
modfact
fact
pfsingle
pfmultiple
ncrsingle
ncrmod
bgmod
mdinverse
sieve
SegmentTree
kmp
bit
sparseTable
vll
pi
ll
Pair
all
mll
mii
mis
msi
vvi
vi
pb
inf
linf
*/