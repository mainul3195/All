#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int l, r;
        cin >> l >> r;
        if(l==r) cout << "0\n";
        else if(r&1)
            cout << r%max(l, (r+1)/2) << "\n";
        else
        {
            if(l>r/2)
                cout << r%l << "\n";
            else cout << (r-1)%((r+1)/2) << "\n";
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