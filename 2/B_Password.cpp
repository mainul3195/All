#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>z_algo(string &str)
{
    int len = str.size();
    int l = 0, r = 0;
    vector<int>z(len, 0);
    for(int i = 1; i<len; i++)
    {
        if(i>r)
        {
            l = r = i;
            while(r<len && str[r] == str[r-l])
                r++;
            z[i] = r-- - l;
        }
        else
        {
            int ind = i - l;
            if(i+z[ind] <= r)
                z[i] = z[ind];
            else
            {
                l = i;
                while(r<len and s[r]==s[r-l])
                    r++;
                z[i] = r-- - l;
            }
        }
    }
    return z;
}
void solve()
{
    cin >> s;
    if(s.size()<3)
    {
        cout << "Just a legend\n";
        return;
    }
    auto z = z_algo(s);
    int mx = 0, len = 0;
    for(int i = 1; i<s.size(); i++)
    {
        if(i+z[i]==s.size() && mx>=z[i])
        {
            len = z[i];
            break;
        }
        else mx = max(mx, z[i]);
    }
    if(len)
        cout << s.substr(0, len);
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