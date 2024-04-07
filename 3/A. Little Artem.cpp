#include<bits/stdc++.h>
#define pi (2*acos(0.0))
#define Swap(x,y) (x)^=(y)^=(x)^=(y)
#define all(x) x.begin(), x.end()
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>>grid(n, vector<char>(m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                grid[i][j] = (i+j)%2? 'W': 'B';
        if(!(n%2) != !(m%2)) grid[n-1][m-1] = 'B';
        else grid[0][m-1] = 'B';
        for(auto i: grid)
        {
            for(auto j: i)
                cout << j;
            cout << "\n";
        }
    }

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