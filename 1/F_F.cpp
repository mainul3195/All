#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int sz = s.size();
    s = '.'+s;
    int len;
    vector<int>isp(s.size(), 0);
    for(int i = 2; i<=sz; i++)
    {
        len = isp[i-1];
        while( len>0 && s[len+1]!=s[i]) 
            len = isp[len];
        isp[i] = len + (s[len+1]==s[i]);
    }
    // for(auto i: isp)
    //     cout << i << " ";
    //     cout << "\n";
    vector<bool>pos(s.size()+2, 0);
    for(int i = 2; i<sz; i++)
        pos[isp[i]] = true;
    for(len = isp[sz]; len>0 ; len = isp[len]) if(pos[len]) break;
    if(len)
    {
        for(int i = 1; i<=len; i++)
            cout << s[i];
            cout << "\n";
    }
    else cout << "Just a legend\n";
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

// /*
// gcd
// lcm
// modfact
// fact
// pfsingle
// pfmultiple
// ncrsingle
// ncrmod
// bgmod
// mdinverse
// sieve
// SegmentTree
// kmp
// bit
// sparseTable
// vll
// pi
// ll
// Pair
// all
// mll
// mii
// mis
// msi
// vvi
// vi
// pb
// inf
// linf
// */
