#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> hights(n);
    for(auto &i: hights)
        cin >> i;
    hights.push_back(0);
    vector<long long> h, ind;
    long long area = 0;
    for(int i = 0; i<=n; i++)
    {
        cout << i << " -> \n";
        cout << "Before \n";
        for(auto j: h)
            cout << j << " ";
            cout << "\n";
        for(auto j: ind)
            cout << j << " ";
            cout << "\n";
        while(h.size() && hights[i]<=h.back())
        {
            area = max(area, h.back()*(i-ind.back()));
            h.pop_back();
            ind.pop_back();
        }
        if(h.empty() || hights[i]>h.back())
        {
            h.push_back(hights[i]);
            ind.push_back(i);
        }
        cout << "after\n";
        for(auto j: h)
            cout << j << " ";
            cout << "\n";
        for(auto j: ind)
            cout << j << " ";
        cout << "\narea= " << area;
            cout << "\n\n";
        
    }
    cout << area << "\n\n\n";
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