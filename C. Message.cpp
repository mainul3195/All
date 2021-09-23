#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
int findsm(string a, string b)
{
    int ans = 0;
    for(int i=0; i<a.size(); i++)
        if(a[i]==b[i])
            ans ++;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string a, b;
    cin >> a >> b;
    int sm = 0;
    for(int i=1; i<= max(a.size(), b.size()) ; i++)
    {
        int f = min(i, (int)a.size());
        int s = min(i, (int)b.size());
        int sz = min(f,s);
        sm = max(sm, findsm(a.substr(a.size()-f, sz), b.substr(s-sz, sz)));
    }
    reverse(all(a));
    reverse(all(b));
    for(int i=1; i<= max(a.size(), b.size()) ; i++)
    {
        int f = min(i, (int)a.size());
        int s = min(i, (int)b.size());
        int sz = min(f,s);
        sm = max(sm, findsm(a.substr(a.size()-f, sz), b.substr(s-sz, sz)));
    }
    cout << b.size()-sm <<  "\n";
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
