#include<bits/stdc++.h>
using namespace std;
int n, oca, ocb;
string a, b;
int calc()
{
    int unmatched = 0;
    for(int i = 0; i<n; i++)
        if(a[i] != b[i])
            unmatched++;
    int mn = unmatched;
    // cout << mn << "\n";
    if(2*ocb-1==n)
    {
        int matched = 0;
        bool onefound = 0;
        for(int i = 0; i<n; i++)
            if(a[i]==b[i])
            {
                matched++;
                if(a[i]=='1')
                    onefound = 1;
            }
        // cout << "vitore -> " <<  unmatched << " " << matched << "\n";
        if(onefound)
            mn = min(mn, matched);
    }
    return mn;
}
void solve()
{
    cin >> n;
    cin >> a >> b;
    if(a==b)
    {
        cout << "0\n";
        return;
    }
    oca = 0, ocb = 0;
    for(auto i: a)
        if(i=='1')
            oca++;
    for(auto i: b)
        if(i=='1')
            ocb++;
    // cout << oca << " " << ocb << "\n";
    if(oca==ocb || ocb == n-oca+1)
    {
        if(oca==ocb)
            cout << calc() << "\n";
        else
        {
            // cout << "eseche?";
            string tmp = a;
            int mn = 2000000000;
            bool done = 0;
            for(int i = 0; !done && i<n; i++)
            {
                if(a[i]=='1' && b[i]=='1')
                {
                    // cout << "before -> " << a << "\n";
                    done = 1;
                    for(int j = 0; j<n; j++)
                        if(i!=j)
                        {
                            if(a[j]=='0')
                                a[j] = '1';
                            else a[j] = '0';
                        }
                    // cout << "first -> " << a << " ";
                    mn = min(mn, 1+calc());
                    // cout << mn << "\n";
                    break;
                }
            }
            done = 0;
            a = tmp;
            for(int i = 0; !done && i<n; i++)
            {
                if(a[i]=='1' && b[i]=='0')
                {
                    done = 1;
                    for(int j = 0; j<n; j++)
                        if(i!=j)
                        {
                            if(a[j]=='0')
                                a[j] = '1';
                            else a[j] = '0';
                        }
                    // cout << "second -> " << a << " ";
                    mn =min(mn, 1+calc());
                    // cout << mn << "\n";
                    break;
                }
            }
            cout << mn << "\n";
        }
        
    }
    else cout << "-1\n";
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