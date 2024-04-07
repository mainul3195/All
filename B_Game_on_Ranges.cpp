#include<bits/stdc++.h>
using namespace std;
struct pr {long long a, b; bool operator < (const pr &x)const {return a<x.a || (a==x.a && b>x.b);}};
void solve()
{
    int n;
    cin >> n;
    vector<pr>v(n);
    for(auto &i: v)
        cin >> i.a >> i.b;
    sort(v.begin(), v.end());
    // for(auto i: v)
    //     cout << i.a << " " << i.b << "\n";
    set<int>st;
    for(int i = 1; i<=n; i++)
        st.insert(i);
    vector<int> ans(n);
    for(int i = n-1; i>=0; i--)
    {
        auto it = upper_bound(st.begin(), st.end(), v[i].a);
        if(it==st.end() || *it>v[i].b)
        {
            it--;
        }
        ans[i] = *it;
        st.erase(it);
    }
    for(int i = 0; i<n; i++)
        cout << v[i].a << " " << v[i].b << " " << ans[i] << "\n";
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