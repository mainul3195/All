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
    string s;
    cin >> s;
    bool ok=1;
    for(int i=0; i<s.size()-1; i++)
    {
        if(s[i]==s[i+1] && s[i]=='1')
        {
            for(++i; i<s.size()-1; i++)
                if(s[i]==s[i+1]&& s[i]=='0')
                {
                    ok=0;
                    break;
                }
        }
        if(!ok)
            break;
    }
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