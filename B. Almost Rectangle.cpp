#include<bits/stdc++.h>
#define ll long long
#define vci vector<int>
#define vcll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mpii map<int, int>
#define mpll map<long long, long long>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<string>v(n);
    for(auto &i: v)
        cin >> i;
    pii pos1, pos2;
    int found = 0;
    for(int i=0; found <2 && i<n ;i++)
    {
        for(int j=0; j<n; j++)
        {
            if(v[i][j]=='*')
            {
                if(!found)
                {
                    pos1 = {i,j};
                    found = 1;
                }
                else 
                {
                    pos2 = {i,j};
                    found ++;
                    break;
                }
            }
        }
    }
    if(pos1.first == pos2.first)
    {
        if(pos1.first == 0)
            pos1.first = pos2.first = 1;
        else
            pos1.first = pos2.first = 0;        
    }
    else if(pos1.second == pos2.second)
    {
        if(pos1.second == 0)
            pos1.second = pos2.second = 1;
        else
            pos1.second = pos2.second = 0;        
    } 
    else
        swap(pos1.first, pos2.first);
    v[pos1.first][pos1.second] = '*';
    v[pos2.first][pos2.second] = '*';
    for(int i=0; i<n; i++)
        cout << v[i] << "\n";
    return;      

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}