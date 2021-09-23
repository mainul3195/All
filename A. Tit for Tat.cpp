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
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int>v(n);
        for(auto &i: v)
            cin >> i;
        for(int i=0; k && i<n-1; i++)
        {
            if(v[i] >= k)
            {
                v[n-1] += k;
                v[i] -= k;
                k = 0;
            }
            else
            {
                v[n-1] += v[i];
                k -= v[i];
                v[i] = 0;
            }
            
        }

        for(auto i: v)
            cout << i << " ";
            cout << "\n";
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