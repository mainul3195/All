#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    set<int> st;
    vector<int> v(n);
    for(auto &i: v)
    {
        cin >> i;
        st.insert(i);
    }
    if(st.size()==1 && *st.begin() == 1)
        cout << n << "\n";
    else
    {
        vector<int> con;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            while(i<n && v[i])
            {
                count++;
                i++;
            }
            if(count)
                con.push_back(count);
        }
        int mx = 0;
        for(auto i: con)
            mx = max(mx, i);
        if(v[0] && v[n-1])
            mx = max(mx, con[0] + con[con.size() - 1]);
        cout << mx << "\n";
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
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