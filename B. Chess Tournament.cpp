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
        int n;
        cin >> n;
        vector<vector<char>>grid(n+1, vector<char>(n+1));
        for(auto &i: grid)
            for(auto &j: i)
                j = '0';
        for(int i=1; i<=n; i++)
            grid[i][i]= 'X';
        string s;
        cin >> s;
        for(int i=0; i<s.size(); i++)
            if(s[i]=='1')
            {
                for(int j=1; j<=n; j++)
                    if(grid[j][i+1]=='0')
                        grid[j][i+1] = '=';
                for(int j=1; j<=n; j++)
                    if(grid[i+1][j]=='0')
                        grid[i+1][j] = '=';
            }

                
        bool ok = 1;
        for(int i=0; i<s.size(); i++)
            if(s[i]=='2')
            {
                int j;
                for(j=1; j<=n; j++)
                    if(grid[j][i+1]=='0')
                    {
                        grid[j][i+1] = '-';
                        grid[i+1][j] = '+';
                        break;
                    }
                if(j==n+1)
                {
                    ok = 0;
                    break;
                }
            }
        // for(auto i: grid)
        // {
        //     for(auto j: i)
        //         cout << j;
        //         cout << "\n";
        // }
        if(!ok)
        {
            cout << "NO\n";
            continue;
        }
        for(auto &i: grid)
            for(auto &j: i)
                if(j=='0')
                    j='=';
        cout << "YES\n";
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                cout << grid[i][j] << (j==n?"\n":"");
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