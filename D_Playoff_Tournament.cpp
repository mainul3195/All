#include<bits/stdc++.h>
using namespace std;
int k, q, lim;
string s;
vector<long long> sg;
void make(int nd = 1)
{
    if((nd<<1)>lim)
    {
        if(s[nd-1]=='?') sg[nd] = 2;
        else sg[nd] = 1;
        return;
    }
    make(nd*2);
    make(nd*2+1);
    char c = s[nd-1];
    if(c=='1') sg[nd] = sg[nd<<1];
    else if(c=='0') sg[nd] = sg[(nd<<1)+1];
    else sg[nd] = sg[nd<<1]+sg[(nd<<1)+1];
    return;
}
void solve()
{
    cin >> k >> s;
    lim = (1<<k)-1;
    sg = vector<long long> (1<<k, 0);
    reverse(s.begin(), s.end());
    make();

    cin >> q;
    while(q--)
    {
        int x;
        char c;
        cin >> x >> c;
        x = lim-x+1;
        s[x-1] = c;
        while(x)
        {
            if((x<<1)>lim)
            {
                if(c=='?') sg[x] = 2;
                else sg[x] = 1;
            }
            else 
            {
                char c = s[x-1];
                if(c=='1') sg[x] = sg[x<<1];
                else if(c=='0') sg[x] = sg[(x<<1)+1];
                else sg[x] = sg[x<<1]+sg[(x<<1)+1];
            }
            x>>=1;
        }
        cout << sg[1] << "\n";
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
*/