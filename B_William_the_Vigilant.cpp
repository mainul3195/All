#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int nos = 0;
    for(int i = 2; i<s.size(); i++)
        if(s[i-2]=='a' && s[i-1] == 'b' && s[i]=='c')
            nos ++;
    while(q--)
    {
        int pos;
        char c;
        cin >> pos >> c;
        pos--;
        if(s[pos]!=c)
        {
            if((s[pos] == 'a' && pos<n-2 && s[pos+1]=='b' && s[pos+2]=='c') ||
            (s[pos]=='b' && pos>0 && pos<n-1 && s[pos-1]=='a'&&s[pos+1]=='c') ||
            (s[pos]=='c' && pos>1 && s[pos-2]=='a' && s[pos-1]=='b'))
                nos--;
            if((c == 'a' && pos<n-2 && s[pos+1]=='b' && s[pos+2]=='c') ||
            (c=='b' && pos>0 && pos<n-1 && s[pos-1]=='a'&&s[pos+1]=='c') ||
            (c=='c' && pos>1 && s[pos-2]=='a' && s[pos-1]=='b'))
                nos++;
        }
        s[pos] = c;
        cout << nos << "\n";
        
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