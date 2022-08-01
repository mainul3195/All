#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &i: v) cin >> i;
    int last = 0;
    for(int i=n-1; i>=0; i--)
        if(v[i]!=i+1)
        {
            last = i+1;
            break;
        }
    double notgonnahappen = last!=0;
    while(m--)
    {
        int in;
        double prb;
        cin >> in >> prb;
        if(in>=last) notgonnahappen *= (1-prb);
    }
    cout << fixed << setprecision(12) <<  1-notgonnahappen << "\n";
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