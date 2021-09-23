#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
struct cond{
    bool mn, on;
    cond()
    {
        mn = on = false;
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        vector<cond> c(n);
        for(auto &i: a)
            cin >> i;
        for(auto &i: b)
            cin >> i;
        bool ok = 1;
        for(int i=1; i<n; i++)
        {
            c[i].mn = c[i-1].mn|a[i-1]==-1;
            c[i].on = c[i-1].on|a[i-1]==1;
        }
        for(int i=0; i<n; i++)
            if((!i && a[i]!=b[i]) || (b[i]>a[i] && !(c[i].on)) || (b[i]<a[i] && !(c[i].mn)))
            {
                ok = 0;
                break;
            }
        cout << (ok?"YES":"NO") << "\n";
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