#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v) cin >> i;
    bool ok = 1;
    int i=0, j = n-1;
    for(; i<j; i++, j--)
    {
        if(v[i]!=v[j])
        {
            int f = v[i], s = v[j];
            bool ok1 = 1, ok2 = 1;
            int l,m;
            for(l = i+1, m = j; l<m; l++, m--)
            {
                if(v[l]!=v[m])
                {
                    if(v[l] != f && v[m] != f)
                    {
                        ok1 = 0;
                        break;
                    }
                    if(v[l]==f) m++;
                    else l--;
                }
            }
            for(l = i, m = j-1; l<m; l++, m--)
            {
                if(v[l]!=v[m])
                {
                    if(v[l] != s && v[m] != s)
                    {
                        ok2 = 0;
                        break;
                    }
                    if(v[l]==s) m++;
                    else l--;
                }
            }
            ok = ok1|ok2;
            break;
        }
    }
    if(ok)
        cout << "YES\n";
    else cout << "NO\n";
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
inf
linf
*/