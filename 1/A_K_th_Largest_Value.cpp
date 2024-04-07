#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int>v(n+1, 0);
    int oc = 0;
    for(int i=1; i<=n; i++)
    {
        cin >> v[i];
        if(v[i]) oc++;
    }
    while(q--)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int x;
            cin >> x;
            if(!v[x])
            {
                oc++;
                v[x] = 1;
            }
            else
            {
                oc--;
                v[x] = 0;
            }
        }
        else
        {
            int k;
            cin >> k;
            if(k<=oc)
                cout << "1\n";
            else cout << "0\n";
        }
    }

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
*/