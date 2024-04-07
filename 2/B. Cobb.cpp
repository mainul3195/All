#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long t;
    cin >> t;
    while(t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long>v(n);
        for(auto &i: v)
            cin >> i;
        long long ans = -10000000000000000;
        for(long long i=max(1ll, n-2*k-1); i<n; i++)
            for(long long j=i+1; j<=n; j++)
                ans = max(ans, i*j - k*(v[i-1]|v[j-1]));
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