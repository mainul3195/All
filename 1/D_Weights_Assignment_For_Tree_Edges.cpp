#include<bits/stdc++.h>
using namespace std;
vector<int> par, p, level, ans;
int n, root;
int findlevel(int i)
{
    if(!level[i]) return level[i];
    return level[i] = 1+level[par[i]];
}
void solve()
{
    cin >> n;
    par = vector<int> (n+1, -1);
    p = vector<int> (n+1, -1);
    level = vector<int> (n+1, -1);
    ans = vector<int> (n+1, -1);
    for(int i=1; i<=n; i++)
    {
        cin >> par[i];
        if(par[i]==i) root = i;
    }
    for(int i=1; i<=n; i++)
        cin >> p[i];
    if(root != p[1])
    {
        cout << "-1\n";
        return;
    }
    level[root] = 0;
    for(int i=1; i<=n; i++)
        findlevel(i);
    int mxlevel = 0;
    for(auto i: level)
        mxlevel = max(mxlevel, i);
    vector<int> wt(mxlevel+2, 0);
    for(int i=1; i<=n; i++)
        wt[level[i]+1]++;
    ans[root] = 0;
    bool ok = 1;
    // for(int i=1; i<=n; i++)
    //     cout << par[i] << " \n"[i==n];
    // for(int i=1; i<=n; i++)
    //     cout << level[i] << " \n"[i==n];
    // for(int i=1; i<=n; i++)
    //     cout << ans[i] << " \n"[i==n];
    int mxans = 0;
    vector<int> tot(n+1, 0);
    for(int i=2; i<=n; i++)
    {
        if(ans[par[p[i]]] == -1)
        {
            // cout << p[i] << " " << par[p[i]] << " " << ans[par[p[i]]] << " " << "khatam" << " " << i << "\n";
            ok = 0;
            break;
        }
        ans[p[i]] = ++mxans-tot[par[p[i]]];
        tot[p[i]] = mxans;
        // cout  << "\n\n" << i << "\n";wt[level[p[i]]]++-ans[par[p[i]]] + mxans +1
        // for(int i=1; i<=n; i++)
        //     cout << par[i] << " \n"[i==n];
        // for(int i=1; i<=n; i++)
        //     cout << level[i] << " \n"[i==n];
        // cout << mxans << "\n";
        // for(int i=1; i<=n; i++)
        //     cout << ans[i] << " \n"[i==n];
    }
    if(!ok)
        cout << "-1\n";
    else
    {
        for(int i=1; i<=n; i++)
            cout << ans[i] << " \n"[i==n];
    }
    
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