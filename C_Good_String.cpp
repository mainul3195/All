#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int ans = 2147483647;
    for(int i=0; i<=9; i++)
        for(int j=0; j<=9; j++)
        {
            bool f = 1;
            int match = 0;
            for(int k = 0; k<s.size(); k++)
                if((f && s[k]=='0'+i) || (!f && s[k]=='0'+j) )
                {
                    match++;
                    f = !f;
                }
            if(match&1 && i!=j) continue;
            ans = min(ans, (int)s.size()-match);
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