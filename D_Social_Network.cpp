#include<bits/stdc++.h>
using namespace std;

vector<int> par, child;
multiset<int>cc;
int getpar(int i)
{
    if(par[i]==i) return i;
    return par[i] = getpar(par[i]);
}
void solve()
{
    int n, d;
    cin >> n >> d;
    for(int i=0; i<=n; i++)
    {
        child.push_back(1);
        par.push_back(i);
    }
    for(int i=0; i<n; i++)
        cc.insert(1);
    int extra = 0;
    // cc.erase(cc.find(1));
    // cc.erase(cc.find(1));
    // for(auto i: cc)
    //     cout << i << " "; 
    //     cout << "\n";
    while(d--)
    {
        int a, b;
        cin >> a >> b;
        int pa = getpar(a);
        int pb = getpar(b);
        // cout << a << " par-> " << pa << "\t" << b << " par-> " << pb << "\n";
        // for(auto i: child)
        //     cout << i << " ";
        //     cout << "\n";
        // for(auto i: par)
        //     cout << i << " ";
        //     cout << "\n";
        if(pa!=pb)
        {
            par[pb] = pa;

            // cout << "before -> \n";
            // for(auto i: cc)
            //     cout << i << " "; 
            //     cout << "\n";
            cc.erase(cc.find(child[pb]));
            cc.erase(cc.find(child[pa]));
            // cout << "after -> \n";
            // for(auto i: cc)
            //     cout << i << " "; 
            //     cout << "\n";

            child[pa] += child[pb];
            cc.insert(child[pa]);
            child[pb] = 0;
        }
        else extra ++;
        // for(auto i: cc)
        //     cout << i << " "; 
        //     cout << "\n";

        int ans = 0;
        auto it = cc.end();
        for(int i=0; i<=extra; i++) 
        {
            it--;
            ans += *it;
            // cout << "ans -> " << ans << "\n";
            if(it==cc.begin())
                break;
        }
        cout << ans-1 << "\n";

        // cout << "\n";
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
inf
linf
*/