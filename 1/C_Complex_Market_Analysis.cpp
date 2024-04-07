#include<bits/stdc++.h>
using namespace std;

#define lim 2000000

bool f[lim+2];

void sieve()
{
    f[1] = 1;
    for(long long i=4; i<=lim; i+=2) f[i] = 1 ;
    for(long long i=3; i*i<=lim; i+=2)
        if(!f[i])
            for(long long j = i*i; j<=lim; j+=2*i)
                f[j] = 1;
    return;
}
void solve()
{
    long long n, e;
    cin >> n >> e;
    vector<long long> v(n), l(n, 0), r(n, 0);
    for(auto &i: v) cin >> i;
    long long ans = 0;
    for(long long i=0; i<n; i++)
    {
        if(v[i]==1)
        {
            l[i]++;
            if(i>=e && v[i-e]==1) l[i] += l[i-e];
        }
    }
    for(long long i=n-1; i>=0; i--)
    {
        if(v[i]==1)
        {
            r[i]++;
            if(i<n-e && v[i+e]==1) r[i]+=r[i+e];
        }
    }
    for(long long i=0; i<n; i++)
        if(!f[v[i]])
        {
            long long prev = 0, after = 0;
            if(i>=e && v[i-e]==1) prev = l[i-e];
            if(i<n-e && v[i+e]==1) after = r[i+e];
            ans += prev+after+prev*after;
        }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    long long t = 1;
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