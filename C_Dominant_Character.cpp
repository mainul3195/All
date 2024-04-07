#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=1; i<n; i++)
        if(s[i]=='a' &&s[i-1]=='a')
        {
            cout << "2\n";
            return;
        }
    for(int i=2; i<n; i++)
        if(s[i]=='a' && s[i-2]=='a')
        {
            cout << "3\n";
            return;
        }
    for(int i=3; i<n ; i++)
        if(s[i]=='a'&&s[i-3]=='a'&&s[i-1]!=s[i-2])
        {
            cout << "4\n";
            return;
        }
    for(int i=6; i<n; i++)
        if(s[i]=='a' && s[i-6]=='a'&&s[i-3]=='a'&&s[i-1]==s[i-2]&&s[i-4]==s[i-5]&&s[i-1]!=s[i-4])
        {
            cout << "7\n";
            return;
        }
    cout << "-1\n";
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