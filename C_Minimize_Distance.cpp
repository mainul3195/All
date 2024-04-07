#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<long long>pos, neg;
    long long a;
    for(long long i = 0; i<n; i++)
    {
        cin >> a;
        if(a>0)
            pos.push_back(a);
        else neg.push_back(-a);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    long long p = (pos.size()?pos.back():0);
    long long ng = (neg.size()? neg.back():0);
    long long ans = 0;
    while(pos.size())
    {
        ans += pos.back();
        for(long long i = 0; pos.size() && i<k; i++)
            pos.pop_back();
    }
    while(neg.size())
    {
        ans += neg.back();
        for(long long i = 0; neg.size() && i<k; i++)
            neg.pop_back();
    }
    cout << 2*ans - max(p, ng) << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
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