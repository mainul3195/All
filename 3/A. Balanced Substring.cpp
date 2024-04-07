#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i;
        for(i=0; i<s.size()-1; i++)
            if(s[i]=='a'&&s[i+1]=='b' || s[i]=='b'&&s[i+1]=='a')
            {
                cout << i+1 << " " << i+2 << "\n";
                break;
            }
        if(i == s.size()-1)
            cout << "-1 -1\n";
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