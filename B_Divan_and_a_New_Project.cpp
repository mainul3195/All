#include<bits/stdc++.h>
using namespace std;
struct pr {long long a, b; bool operator < (const pr &x)const {return a>x.a || (a==x.a && b<x.b);}};

void solve()
{
    long long n;
    // cout << "run\n";
    cin >> n;
    vector<pr>v, tmp;
    for(long long i=1; i<=n; i++)
    {
        long long j;
        cin >> j;
        v.push_back({j, i});
    }
    tmp = v;
    sort(v.begin(), v.end());
    vector<long long>frnt, back;
    for(long long i=0; i<v.size(); i++)
    {
        if(!(i%2))
            back.push_back(v[i].b);
        else frnt.push_back(v[i].b);
    }
    // // for(auto i: frnt)
    // //     cout << i << " ";
    // //     cout << "\n";
    // // for(auto i: back)
    // //     cout << i << " ";
    // //     cout << "\n";
    vector<long long> ans(n+1, 0);
    for(int i=frnt.size()-1; i>=0; i--)
        ans[frnt[i]] = -i-1;
    for(int i=0; i<back.size(); i++)
        ans[back[i]] = i+1;
    long long tot = 0;
    for(int i=1; i<=n; i++)
        tot += abs(ans[i]-ans[0])*2*tmp[i-1].a;
    cout << tot << "\n";
    for(auto i: ans)
        cout << i << " ";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t = 1;
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