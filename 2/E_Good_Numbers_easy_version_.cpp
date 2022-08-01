#include<bits/stdc++.h>
using namespace std;
vector<int> p3, allgood;
void solve()
{
    int n;
    cin >> n;
    cout << *upper_bound(allgood.begin(), allgood.end(), n-1) << "\n";
    return;
}
bool isGood(int x)
{
    for(int i = p3.size(); x && i>=0; i--)
        if(x>=p3[i])
            x -= p3[i];
    return !x;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int mul = 1;
    for(; mul<=100005; mul *=3)
        p3.push_back(mul);
    for(int i = 1; i<19700; i++)
        if(isGood(i))
            allgood.push_back(i);
    // for(auto i: allgood)
    //     cout << i << "\n";
    // for(auto i: p3)
    //     cout << i << "\n";
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