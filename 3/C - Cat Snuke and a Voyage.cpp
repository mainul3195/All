#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v[n+1];
    for(int i=0; i<m; i++)
    {
        int j, k;
        cin >> j >> k;
        v[j].push_back(k);
        v[k].push_back(j);
    }
    int ans = 0;
    for(auto i: v[1])
        if(!ans)
            for(auto j: v[i])
                if(j==n)
                {
                    ans = 1;
                    break;
                }
    if(ans)
        cout << "POSSIBLE\n";
    else 
        cout << "IMPOSSIBLE\n";
    return 0;
}