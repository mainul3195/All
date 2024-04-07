#include<bits/stdc++.h>
using namespace std;
struct pr {long long a, b; bool operator < (const pr &x)const {return a<x.a || (a==x.a && b<x.b);}};

int n;
vector<pr>dhong;

bool hobeki(int target)
{
    int done = 0;
    int baki = target-1;
    for(int i=0; i<n; i++)
    {
        if(dhong[i].a >= baki && dhong[i].b >= done)
        {
            done++;
            baki--;
            if(done == target) return 1;
        }
    }
    return 0;
}
void solve()
{
    cin >>  n;
    dhong = vector<pr>(n);
    for(auto &i: dhong)
        cin >> i.a >> i.b;
    int l = 1, r = n, mid, ans = 1;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(hobeki(mid))
        {
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
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
inf
linf
*/