#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    set<int>st;
    for(int i = 0; i<n; i++)
    {
        int j;
        cin >> j;
        mp[j]++;
    }
    int ans = 0;
    for(auto [i, j]: mp)
    {
        if(j>1)
            st.insert(-i);
        st.insert(i);
    }
    cout << st.size() << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
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