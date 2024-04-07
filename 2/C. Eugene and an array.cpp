#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long n;
    cin >> n;
    vector<long long> num(n+2), cs(n+2, 0);
    long long noz = 0, st = 100000000, end = -1;
    map<long long, long long>mp;
    mp[0]=1;
    for(long long i=2; i<=n+1; i++)
    {
        long long j;
        cin >> j;
        if(!j) noz ++;
        cs[i] = cs[i-1]+j;
        if(mp[cs[i]])
        {
            end = max(end, mp[cs[i]]+1);
            st = min(st, i);
        }
        mp[cs[i]] = i;
    }
    st -= 2, end;
    if(end != -1)
        cout << (n-noz + max(0ll, st-1) + max(0ll, n-end)) << "\n";
    else cout << max(1ll,3*n - 3) << "\n";

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