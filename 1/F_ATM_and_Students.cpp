#include<bits/stdc++.h>
using namespace std;
long long n, s;
vector<long long> sq , sgtree;
void make(int node = 1, int l=1, int r=n)
{
    if(l==r)
    {
        sgtree[node] = sq[l];
        return;
    }
    int mid = (l+r)/2;
    int left = node<<1;
    int right = left+1;
    make(left, l, mid);
    make(right, mid+1, r);
    sgtree[node] = min(sgtree[left], sgtree[right]);
    return;
}
long long query(int l, int r, int node = 1, int start = 1, int end = n)
{
    if(r<start || end<l) return 922337203685477;
    if(start>=l && end <=r ) return sgtree[node];
    return min(query(l, r, node<<1, start, (start+end)>>1), query(l, r, (node<<1)+1, ((start+end)>>1)+1, end));
}
int spos, epos;
bool possible(int len)
{
    for(int i=len; i<=n; i++)
        if(query(i-len+1, i)-sq[i-len]+s>=0)
        {
            spos = i-len+1;
            epos = i;
            return 1;
        }
    return 0;
}
void solve()
{
    cin >> n >> s;
    sq = vector<long long> (n+1, 0);
    sgtree = vector<long long> (4*n, 9223372036854775);
    for(int i=1; i<=n; i++)
    {
        cin >> sq[i];
        sq[i]+=sq[i-1];
    }
    make();
    int ans = -1;
    int l = 1, r = n, mid;
    spos = -1, epos = -1;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(possible(mid))
            l = mid+1;
        else r = mid-1;
    }
    if(spos==-1) cout << "-1\n";
    else cout << spos << " " << epos << "\n";
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