#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int k;
    string s;
    cin >> k >> s;
    int l = (s.size()-1)/2;
    int r = s.size()/2;
    int ar[26] = {0};
    for(auto i: s)
        if(i>='a' && i<='z')
            ar[i-'a'] = 1;
    set<char>notfilled;
    for(int i = 0; i<k; i++)
        if(!ar[i])
            notfilled.insert(i+'a');
    for(; notfilled.size() && l>=0 && r<s.size(); l--, r++)
        if(s[l]=='?' && s[r]=='?')
        {
            auto it = notfilled.end(); it--;
            s[l] = s[r] = *it;
            notfilled.erase(it);
        }
    for(l = 0, r = s.size()-1; l<r; l++, r--)
        if((s[l]=='?' || s[r]=='?') && !(s[l]=='?' && s[r]=='?'))
            s[l]=='?'?s[l] = s[r]: s[r] = s[l];
    bool ok = 1;
    for(l = 0, r = s.size()-1; l<=r; l++, r--) if(s[l] != s[r])
    {
        ok = 0;
        break;
    }
    for(auto &i: s)
        if(i=='?')
            i = 'a';
    // cout << int(ok) << " " << notfilled.size() << "\n";
    if(ok && !notfilled.size())
        cout << s << "\n";
    else cout << "IMPOSSIBLE\n";
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