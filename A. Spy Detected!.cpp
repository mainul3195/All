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
    int n,i;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v)
        cin >> i;
    bool found = 0;
    for(i=0; !found && i<v.size()-1; i++)
    {
        if(!i && v[i]!=v[i+1] && v[i+1]==v[i+2])
        {
            cout << "1\n";
            return;
        }
        else if(v[i-1]!=v[i] && v[i-1]==v[i+1])
        {
            cout << i+1 << "\n";
            return;
        }
    }
    cout << n << "\n";
    return ;
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