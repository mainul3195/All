#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    string s = "";
    cin >> n >> k;
    for(int i = 0; i<k; i++)
    {
        s+='a'+i;
        for(int j = i+1; j<k; j++)
        {
            s+='a'+i;
            s+='a'+j;
        }
    }
    // cout << s << "\n";
    string ans = "";
    while(ans.size()<n)
        ans += s;
    for(int i = 0; i<n; i++)
        cout << ans[i];
        cout << "\n";
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