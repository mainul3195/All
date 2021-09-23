#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        vector<int>v(3);
        int m;
        for(auto &i: v)
            cin >> i;
        cin >> m;
        sort(all(v));
        int mx = v[0]+v[1]+v[2]-3;
        int mn = max(0,v[2]-(v[1]+v[0]+1));
        if(m>=mn && m<=mx)
            cout << "YES\n";
        else cout << "NO\n";
    }

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
*/