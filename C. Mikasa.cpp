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
        int n, m;
        cin >> n >> m;
        int ans = 0;
        if(n<=m)
            while((ans^n) <= m)
            {
                int temp = ans + n;
                int i;
                for(i=0; temp<=m && i<32; i++)
                    temp |= 1<<i;
                ans += (1<<(i-1));
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