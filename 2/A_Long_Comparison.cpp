#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int e1, e2;
    string n1, n2;
    cin >> n1 >> e1 >> n2 >> e2;
    int tot1 = n1.size()+e1;
    int tot2 = n2.size()+e2;
    if(tot1<tot2)
    {
        cout << "<\n";
        return;
    }
    if(tot1>tot2)
    {
        cout << ">\n";
        return;
    }
    if(n1.size()<n2.size())
    {
        int add = min((int)(n2.size() - n1.size()), e1);
        for(int i = 0; i<add; i++)
            n1 += '0';
    }
    else if(n1.size()>n2.size())
    {
        int add = min((int)(n1.size()-n2.size()), e2);
        for(int i = 0; i<add; i++)
            n2+='0';
    }
    if(n1>n2)
        cout << ">\n";
    else if(n1<n2)
        cout << "<\n";
    else cout << "=\n";
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