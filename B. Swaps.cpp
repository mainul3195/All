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
        int n;
        cin >> n;
        vector<int>a(n), b(n), bmx(2*n+5), index(2*n+5);
        index[2*n+2] = 20000000;
        for(auto &i: a)
            cin >> i;
        for(int i=0; i<n; i++)
        {
            cin >> b[i];
            index[b[i]] = i;
        }
        int mn = 1000000;
        for(int i= 2*n; i>0; i-=2)
        {
            if(index[i]<mn)
                mn = index[i];
            bmx[i] = mn;
        }
        int ans = 100000000;
        for(int i=0; i<n; i++)
            ans = min(ans, i+bmx[a[i]+1]);
        cout << ans << "\n";
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