#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int>acs(n+1,0), nac(n+1, 0), nex(n+1,0);
    vector<bool> pos(n+1, false);
    int totex = 0;
    for(int i=1; i<=n; i++)
    {
        cin >> acs[i];
        acs[i]>0?nac[acs[i]]++:(nex[-acs[i]]++, totex++);
    }
    for(int i=1; i<=n; i++) if(nac[i]+totex-nex[i] == m)pos[i] = true;
    vector<string>ans(n+1,"");
    int possible = 0;
    for(int i=1; i<=n; i++)
        if(pos[i]) possible ++;
    int notr=0;
    vector<bool> definite(n+1, false);
    for(int i=1; i<=n; i++)
    {
        if(acs[i]>0)
        {
            if(pos[acs[i]])
            {
                ans[i] = "Truth";
                notr++;
                if(possible==1) definite[i] = true;
            } 
            else ans[i] = "Lie";
        }
        else
        {
            if(pos[-acs[i]] == false || (pos[-acs[i]] && possible>1))
            {
                ans[i] = "Truth";
                notr++;
                if(pos[-acs[i]] == false) definite[i] = true;
            }
            else ans[i] = "Lie";
        }
    }
    if(notr != m)
        for(int i=1; i<=n; i++)
            if(ans[i]=="Truth" && !definite[i])
                ans[i] = "Not defined";
    for(int i=1; i<=n; i++)
        cout << ans[i] << "\n";
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
*/