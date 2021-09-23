#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
#define Mod 1000000007
long long bigMod(int b, int p)
{
    if(!p) return 1;
    if(p&1) return (b*bigMod(b, p-1))%Mod;
    long long T = bigMod(b, p/2);
    return (T*T)%Mod;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        long long n, k;
        cin >> n >> k;
        if(n%2)
            cout << bigMod((bigMod(2, n-1) + 1),k) << "\n";
        else
        {
            long long evensum = bigMod(2, n-1);
            long long frstpart =  bigMod((evensum - 1),k);
            long long exp = bigMod(2, n);
            long long scndpart = 0;
            for(long long i = 1; i<=k; i++)
                scndpart = (scndpart +  (bigMod(evensum-1, k-i)*bigMod(exp, i-1))%Mod  )%Mod;
            cout << (frstpart+scndpart)%Mod << "\n";
        }
        
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