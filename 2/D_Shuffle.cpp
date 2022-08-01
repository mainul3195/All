#include<bits/stdc++.h>
using namespace std;
//complexity: O(n)
//Must call precalc
#define max_lim 100000
#define Mod 998244353
vector<long long>f(max_lim+1);
void precalc()
{
    f[0]=1;
    for(long long i=1; i<=max_lim; i++)
        f[i]=f[i-1]*i%Mod;
    return;
}
long long bigMod(long long b, long long p)
{
    if(!p) return 1;
    if(p&1) return (b*bigMod(b, p-1))%Mod;
    long long T = bigMod(b, p/2);
    return (T*T)%Mod;
}
long long modInverse(long long n)
{
    return bigMod(n, Mod-2);
}
long long nCr(long long n, long long r)
{
    return (((f[n]*modInverse(f[r]))%Mod)*modInverse(f[n-r]))%Mod;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> bef(n), af(n);
    int tm = 0;
    for(int i = 0; i<n; i++)
    {
        bef[i] = tm;
        if(s[i]=='1')
            tm = i+1;
    }
    tm =  n-1;
    for(int i = n-1; i>=0; i--)
    {
        af[i] = tm;
        if(s[i]=='1')
            tm = i-1;
    }
    // for(auto i: bef)
    //     cout << i << " ";
    //     cout << "\n";
    // for(auto i: af)
    //     cout << i << " ";
    //     cout << "\n";

    vector<int>one;
    for(int i =0 ; i<n ; i++)
        if(s[i] == '1')
            one.push_back(i);
    if(!k || k>one.size())
    {
        cout << "1\n";
        return;
    }
    int start = 0, end = k-1;
    long long ans = 0;
    bool firsttime = 1;
    for(; end<one.size(); start++, end++)
    {
        long long tot = nCr(af[one[end]] - bef[one[start]] + 1, k);
        long long done = 0;
        if(!firsttime)
        {
            if(k==1)
                done = 1;
            else done = nCr(af[one[end-1]] - bef[one[start]] +1 , k-1);
        }
        firsttime = 0;
        // cout << "\n";
        // cout << start << " " << end << " " << tot << " " << done << "\n";
        // cout << one[start] <<  " " << one[end-1] << " " << one[end] << " " << bef[one[start]] << " " << af[one[end-1]] << " " << af[one[end]] << "\n";
        ans  = (ans + tot - done + Mod) % Mod;

    }
    cout << ans << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    precalc();
    int t = 1;
    // cin >> t;
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