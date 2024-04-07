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
    vector<int>X;
    X.push_back(0);
    for(int i=1; i<=3000070; i++)
        X.push_back(X[i-1]^i);
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = a;
        // cout << X[a-1] <<" ";
        if(X[a-1]!=b)
        {
            if(X[a-1]==0)
                b!=a?ans++:ans+=2;
            else (X[a-1]^b) == a? ans+=2: ans++;
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