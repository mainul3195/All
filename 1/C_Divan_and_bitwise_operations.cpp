#include<bits/stdc++.h>
using namespace std;
struct pr {long long a, b, c; bool operator < (const pr &x)const {return a<x.a || (a==x.a && b<x.b);}};
#define Mod 1000000007
long long bigMod(long long b, long long p)
{
    if(!p) return 1;
    if(p&1) return (b*bigMod(b, p-1))%Mod;
    long long T = bigMod(b, p/2);
    return (T*T)%Mod;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<long long > v(n+5, 0);
    vector<pr>seg(m);
    for(auto &i: seg)
        cin >> i.a >> i.b >> i.c;
    sort(seg.begin(), seg.end());
    long long  mx = 1;
    for(auto i: seg)
    {
        if(i.b<mx) continue;
        mx = max(mx, i.a);
        v[mx] += i.c;
        v[i.b+1] -= i.c;
        mx = i.b+1;
    }
    long long Or = 0;
    for(int i=1; i<=n; i++)
    {
        v[i]+=v[i-1];
        Or |= v[i];
    }
    cout << (Or * bigMod(2, n-1))%Mod << "\n";

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