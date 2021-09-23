#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define all(x) x.begin(), x.end()
using namespace std;
//returns 0 base index of first found in text or -1
vector<int> matchString(const string &text,const string &pattern)
{
    vector<int> ans;
    vector<int>isp(pattern.size(), -1);
    int l = -1, r = 1;
    while(r<pattern.size())
    {
        if(pattern[l+1] == pattern[r]) isp[r++] = ++l;
        else
        {
            if(!l) l = -1;
            else if(l>0) l = isp[l-1];
            else r++;
        }
    }
    l = -1, r = 0;
    while(r<text.size())
    {
        if(pattern[l+1] == text[r]) r++,l++;
        else l>=0? l = isp[l]: r++;

        if(l == pattern.size() - 1) ans.push_back(r-pattern.size()), l = isp[l];
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    while(cin >> n)
    {
        string a, b;
        cin >> a >> b;
        vector<int> v = matchString(b,a);
        if(v.size())
        {
            for(auto i: v)
                cout << i << "\n";
                cout << "\n";
        }
    }
    

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
*/