#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>>grid(n, vector<int>(n));
    for(auto &i: grid)
        for(auto &j: i)
            cin >> j;
    vector<int> rowsum(n, 0);
    vector<int> colsum(n, 0);
    for(int i=0;  i<n; i++)
        for(int j=0; j<n; j++)
        {
            rowsum[i] += grid[i][j];
            colsum[j] += grid[i][j];
        }
    int ans =0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(colsum[j]>rowsum[i]) ans ++;
    cout << ans << "\n";
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