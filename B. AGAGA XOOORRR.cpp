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
        cin >>  n;
        int ans = 0;
        int j;
        vector<int>v(n), l, r;
        for(auto &i: v)
            cin >> i, ans ^= i;
        if(!ans) cout << "YES\n";
        else
        {
            int temp = 0;
            int count = 0;
            for(int i=0; i<n; i++)
            {
                temp ^= v[i];
                if(temp == ans)
                    temp = 0, count++;
            }
            if(count>1 && !temp) cout << "YES\n";
            else cout << "NO\n";
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