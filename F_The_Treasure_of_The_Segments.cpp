#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> s, e;
struct pr {long long a, b; bool operator < (const pr &x)const {return a<x.a || (a==x.a && b<x.b);}};
int low(int v)
{
    int ans = -1;
    int l = 0, r = n-1, mid;
    while(l<=r)
    {
        mid = (l+r)>>1;
        if(e[mid]<v)
        {
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return ans+1;
}
int high(int v)
{
    int ans = 0;
    int l = 0, r = n-1, mid;
    while(l<=r)
    {
        mid = (l+r)>>1;
        if(s[mid]>v)
        {
            ans = n-mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    return ans;
}
void solve()
{
    cin >> n;
    vector<pr>sg;
    s.clear();
    e.clear();
    for(int i=0; i<n; i++)
    {
        int l, r;
        cin >> l >> r;
        s.push_back(l);
        e.push_back(r);
        sg.push_back({l, r});
    }
    sort(s.begin(), s.end());
    sort(e.begin(), e.end());
    int ans = 10000000;
    for(auto i: sg)
        ans = min(ans, low(i.a)+high(i.b));
    cout << ans << "\n";
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
*/