#include<bits/stdc++.h>
using namespace std;
struct nd 
{
    int ind, val, like;
    bool operator<(const nd &a)const
    {
        return val<a.val;
    }
};
bool cmp(nd &a, nd &b)
{
    return a.ind <b.ind;
}
void solve()
{
    int n;
    cin >> n;
    vector<nd>v;
    for(int i = 0; i<n; i++)
    {
        int j;
        cin >> j;
        v.push_back({i, j, 0});
    }
    string s;
    cin >> s;
    int tot1 = 0;
    for(int i = 0; i<n; i++)
        if(s[i]=='1')
            v[i].like = 1, tot1++;
    if(tot1 == n || !tot1)
    {
        for(auto i: v)
            cout << i.val << " ";
            cout << "\n";
        return;
    }
    sort(v.begin(), v.end());
    set<int>in;
    for(int i = 0; i<n; i++)
        if(v[i].like)
            in.insert(i);
    for(int i = n-tot1; i<n; i++)
        if(!v[i].like)
        {
            int index = *in.begin();
            swap(v[i].val, v[index].val);
            in.erase(in.begin());
        }
    sort(v.begin(), v.end(), cmp);
    for(auto i: v)
        cout << i.val << " ";
        cout << "\n";
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