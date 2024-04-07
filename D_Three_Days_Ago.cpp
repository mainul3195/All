#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<vector<int>>v(10, vector<int>(s.size(), 0));
    for(int i = 0; i<s.size(); i++)
        v[s[i]-'0'][i]++;
    for(int i = 0; i<10; i++)
        for(int j = 1; j<s.size(); j++)
            v[i][j] += v[i][j-1];
    
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve(); 
    return 0;
}