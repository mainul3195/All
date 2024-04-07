#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
//complexity: O(n)
//Must call precalcRead it first
#define max_lim 200005
#define Mod 998244353 
vector<long long>f(max_lim+1);
void precalc()
{
    f[0]=1;
    for(int i=1; i<=max_lim; i++)
        f[i]=f[i-1]*i%Mod;
}
long long factorial(int n)
{
    return f[n];
}
long long bigMod(int b, int p)
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
long long nCr(int n, int r)
{
    return (((f[n]*modInverse(f[r]))%Mod)*modInverse(f[n-r]))%Mod;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    precalc();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<long long>v(n);
        for(auto &i: v)
            cin >> i;
        sort(all(v));
        long long ans=0;
        if(v[n-1]==v[n-2]) ans = factorial(n);
        else if(v[n-2]<v[n-1]-1) ans = 0;
        else
        {
            long long tmp = factorial(n-1);
            long long ls = (upper_bound(all(v), v[n-1]-2) - v.begin());
            for(int i=n-2; i>0; i--)
            {
                if(ls<n-i-1) break;
                tmp += ((nCr(ls, n-i-1)*factorial(n-i-1)%Mod)*factorial(i))%Mod;
                tmp = tmp%Mod;
            }
            ans = (factorial(n)-tmp+Mod)%Mod;
        }
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