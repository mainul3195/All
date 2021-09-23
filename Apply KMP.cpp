#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define all(x) x.begin(), x.end()
using namespace std;
//returns 0 base index of first found in text or -1
int matchString(const string &text,const string &pattern)
{
    if(text.size()<pattern.size()) return 0;
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
    int count = 0;
    while(r<text.size())
    {
        if(pattern[l+1] == text[r]) r++,l++;
        else l>=0? l = isp[l]: r++;

        if(l == pattern.size() - 1) count ++, l = isp[l];
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string a, b;
    cin >> a >> b;
    cout << matchString(b, a) << "\n";

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