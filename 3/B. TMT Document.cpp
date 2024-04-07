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
    string s;
    cin >> s;
    int count=0;
    bool ok=1;
    for(auto i:s)
    {
        if(i=='T')
            count ++;
        else if(i=='M')
            count --;
        if(count<0)
        {
            ok=0;
            break;
        }
    }
    if(count != n/3)
        ok=0;
    reverse(s.begin(), s.end());
    count=0;
    for(auto i:s)
    {
        if(i=='T')
            count ++;
        else if(i=='M')
            count --;
        if(count<0)
        {
            ok=0;
            break;
        }
    }
    if(count != n/3)
        ok=0;
    if(ok)
        cout << "YES\n";
    else 
        cout << "NO\n";
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