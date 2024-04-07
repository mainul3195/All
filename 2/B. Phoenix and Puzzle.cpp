#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    set<long long>st;
    for(int i=1; i*i<=1000000000; i++)
    {
        st.insert(i*i*2);
        st.insert(i*i*4);
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(st.find(n)!=st.end())
            cout << "YES\n";
        else cout << "NO\n";
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