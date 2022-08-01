#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> b(n);
    long long tot = 0;
    for(auto &i: b)
    {
        cin >> i;
        tot += i;
    }
    if((2*tot)%(n*(n+1)))
    {
        cout << "NO\n";
        return;
    }
    long long s = 2*tot/n/(n+1);
    vector<int> ans;
    for(int i = 0; i<n; i++)
    {
        long long tmp = s + b[(i-1+n)%n] - b[i];
        if(tmp<=0 || tmp%n)
        {
            cout << "NO\n";
            return;
        }
        ans.push_back(tmp/n);
    }
    cout << "YES\n";
    for(auto i: ans)
        cout << i << " ";
        cout << "\n";
    
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