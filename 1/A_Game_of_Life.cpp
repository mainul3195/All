#include<bits/stdc++.h>
using namespace std;
int n, m;
string s;
int nb1c(int i)
{
    return (i>0&&s[i-1]=='1')+(i<n-1 && s[i+1]=='1');
}
void solve()
{
    cin >> n >> m;
    string tmp;
    cin >> s;
    tmp = s;
    int lim  = min(n, m);
    for(int j=0; j<lim; j++)
    {
        for(int i=0; i<n; i++)
            if(s[i]=='0' && nb1c(i)==1)
                tmp[i]= '1';
        s = tmp;
    }
    cout << s << "\n";
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