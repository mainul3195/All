#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l=0, r = n-1;
    vector<int> ans;
    while(l<r)
    {
        while(r>=0 && s[r]!='0')r--;
        while(l<r&&l<n && s[l]!='1') l++;
        if(l<r)
        {
            ans.push_back(l+1);
            ans.push_back(r+1);
        }
        l++, r--;
    }
    sort(ans.begin(), ans.end());
    if(ans.size())
        cout << "1\n" << ans.size() << " ";
    else cout << "0\n";
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " \n"[i==ans.size()-1];
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